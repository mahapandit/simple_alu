#include <verilated.h>  // verilator module
#include <verilated_fst_c.h>   // All verilator waveform paths and dependency
#include "Valu.h" 
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <vector>

enum AluOpcode : uint8_t {
    OP_ADD  = 0x00,
    OP_SUB  = 0x01,
    OP_SLL  = 0x02,
    OP_SRL  = 0x03,
    OP_SRA  = 0x04,
    OP_SLT  = 0x05,
    OP_SLTU = 0x06,
    OP_XOR  = 0x07,
    OP_OR   = 0x08,
    OP_AND  = 0x09,
    OP_INV1 = 0xFF,  // For testing default/invalid opcode flag
    OP_INV2 = 0xAA 
};


struct GoldenResult {
    uint32_t outdata;
    uint8_t  flag_bus;
};


GoldenResult compute_golden(uint32_t a, uint32_t b, uint8_t op, uint8_t intrupts) {
    GoldenResult res = {0,0} ;
    
    if (intrupts & 0x1) {   //0x1 == 0001
        return res; // Async reset active
    }

    uint64_t wide_res = 0;
    uint32_t shamt = b & 0x1F; // 1F coz, we have set the SLL to indata2[4:0] bits only

    switch (op) {
            case OP_ADD:
                wide_res = (uint64_t)a + (uint64_t)b;
                res.outdata = (uint32_t)wide_res;
                res.flag_bus = (wide_res >> 32) & 0x1;  // swift out first32, and and it with 0000_0000_0000_0000_0000_0000_0000_0001 >> go get the flag 
                break;
            case OP_SUB:
                wide_res = (uint64_t)a - (uint64_t)b;
                res.outdata = (uint32_t)wide_res;
                res.flag_bus = (wide_res >> 32) & 0x1; // 1-bit borrow/carry
                break;
            case OP_SLL:
                res.outdata = a << shamt;
                break;
            case OP_SRL:
                res.outdata = a >> shamt;
                break;
            case OP_SRA:
                res.outdata = (uint32_t)((int32_t)a >> shamt);  // singned_no does then shift. And at the end take it as signal number, that is unsiged. So that TB doesnt glitch out
                break;
            case OP_SLT:
                res.outdata = ((int32_t)a < (int32_t)b) ? 1U : 0U;
                break;
            case OP_SLTU:
                res.outdata = (a < b) ? 1U : 0U;
                break;
            case OP_XOR:
                res.outdata = a ^ b;
                break;
            case OP_OR:
                res.outdata = a | b;
                break;
            case OP_AND:
                res.outdata = a & b;
                break;
            default:
                res.outdata = 0;
                res.flag_bus = 0x80; // flag_bus[7] = 1'b1
                break;
        }
        return res;
    }


int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);   // veriloater 
    Verilated::traceEverOn(true);  //verilator waveform

    Valu* dut = new Valu;
    VerilatedFstC* tfp = new VerilatedFstC;
    dut->trace(tfp, 99);
    tfp->open("sim.fst");

    uint64_t sim_time = 0;
    uint32_t fail_count = 0;

    auto apply_and_check = [&](uint32_t a, uint32_t b, uint8_t op, uint8_t intr) {
        dut->indata1  = a;
        dut->indata2  = b;
        dut->opcode   = op;
        dut->intrupts = intr;

        dut->eval();
        tfp->dump(sim_time++);

        GoldenResult exp = compute_golden(a, b, op, intr);

        if (dut->outdata != exp.outdata || dut->flag_bus != exp.flag_bus) {
            std::printf("[FAIL] t=%llu | op=0x%02X intr=0x%02X | in1=0x%08X in2=0x%08X | "
                        "RTL: out=0x%08X flag=0x%02X != EXP: out=0x%08X flag=0x%02X\n",
                        (unsigned long long)sim_time, op, intr, a, b,
                        dut->outdata, dut->flag_bus, exp.outdata, exp.flag_bus);
            fail_count++;
        }
    };

    // 1. Test Async Reset (intrupts[0] = 1)
    apply_and_check(0xFFFFFFFF, 0x00000001, OP_ADD, 0x01);
    //apply_and_check(0xFFFFFFFF, 0x00000001, OP_ADD, 0x00);

    // 2. Test Invalid Opcode (flag_bus[7] assertion)
    apply_and_check(0x12345678, 0x87654321, OP_INV1, 0x00);
    apply_and_check(0x12345678, 0x87654321, OP_INV2, 0x00);

    // 3. Week 1 Corner-Case Vectors across all 10 valid opcodes
    const std::vector<uint32_t> corners = {
        0x00000000, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF, 0x00000001, 0x0000001F, 0x00000022
    };

    for (uint8_t op = OP_ADD; op <= OP_AND; ++op) {
        for (uint32_t a : corners) {
            for (uint32_t b : corners) {
                apply_and_check(a, b, op, 0x00);
            }
        }
    }

    // 4. 1,000 Random Vectors
    std::mt19937 rng(0xC0FFEE); // Fixed seed for reproducibility
    std::uniform_int_distribution<uint32_t> dist32(0, 0xFFFFFFFF);
    std::uniform_int_distribution<int> dist_op(OP_ADD, OP_AND);

    for (int i = 0; i < 1000; ++i) {
        apply_and_check(dist32(rng), dist32(rng), (uint8_t)dist_op(rng), 0x00);
    }

    tfp->close();
    delete tfp;
    delete dut;

    if (fail_count > 0) {
        std::printf("\nSimulation FAILED with %u mismatched vectors.\n", fail_count);
        return EXIT_FAILURE;
    }

    std::printf("\nSimulation PASSED! All corner and random vectors verified (%llu total cycles).\n",
                (unsigned long long)sim_time);
    return EXIT_SUCCESS;
}
