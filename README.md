# 32-bit ALU

A 32-bit arithmetic logic unit implemented in SystemVerilog and tested with a
C++ testbench using Verilator.

## Operations

| Opcode | Operation |
| ------ | --------- |
| `0x00` | Add |
| `0x01` | Subtract |
| `0x02` | Shift left logical |
| `0x03` | Shift right logical |
| `0x04` | Shift right arithmetic |
| `0x05` | Set if less than (signed) |
| `0x06` | Set if less than (unsigned) |
| `0x07` | Bitwise XOR |
| `0x08` | Bitwise OR |
| `0x09` | Bitwise AND |

The `intrupts[0]` input clears the output and flags when asserted. `flag_bus[0]`
reports the add/subtract carry bit, and `flag_bus[7]` is set for an invalid
opcode.

## Requirements

- Verilator
- A C++ compiler
- GTKWave (optional, for viewing simulation waveforms)

## Build and test

Run the simulation and testbench:

```sh
make sim
```

The testbench checks corner cases and 1,000 reproducible random vectors. A
successful run prints `Simulation PASSED!` and generates `sim.fst`.

To view the waveform after running the simulation:

```sh
make wave
```

To remove generated build and waveform files:

```sh
make clean
```

## Files

- `alu.sv` — ALU implementation
- `tb_alu.cpp` — Verilator C++ testbench
- `Makefile` — build, simulation, waveform, and cleanup targets
