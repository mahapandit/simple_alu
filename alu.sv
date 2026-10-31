`define DATA_WIDTH 32
`define WORD 8 

`define opcode_alu_add 8'b0000_0000
`define opcode_alu_sub 8'b0000_0001
`define opcode_alu_sll 8'b0000_0010
`define opcode_alu_srl 8'b0000_0011
`define opcode_alu_sra 8'b0000_0100
`define opcode_alu_slt 8'b0000_0101
`define opcode_alu_sltu 8'b0000_0110
`define opcode_alu_xor 8'b0000_0111
`define opcode_alu_or 8'b0000_1000
`define opcode_alu_and 8'b0000_1001

// input intruppts
// intrupts[0] is async reset

//output flag_bus 
// flag_bus[`WORD-1] is invalid opcode
// flag_bus[0] is carry

module alu (
input wire [`DATA_WIDTH-1:0] indata1, 
input wire [`DATA_WIDTH-1:0] indata2,
input wire [`WORD-1:0] opcode,
input wire [`WORD-1:0] intrupts,
output reg [`DATA_WIDTH-1:0] outdata,
output reg [`WORD-1:0] flag_bus
) ;

always_comb begin 
    flag_bus ='0 ; 
    outdata = '0 ; 
    if (intrupts[0]) begin 
        outdata = '0 ; 
        flag_bus = '0 ;
    end
    else begin 
        case(opcode)
            `opcode_alu_add : {flag_bus[0], outdata} = indata1 + indata2;  
            `opcode_alu_sub : {flag_bus[0], outdata} = indata1 - indata2;
            `opcode_alu_sll : outdata = ( indata1 << indata2[4:0] ) ;  // shift left logical
            `opcode_alu_srl : outdata = indata1 >> indata2[4:0]; // shift right logical
            `opcode_alu_sra : 
            // shift right arithmetic : 1000_1000 >> 2 = 0010_0010 (SRL) + 
            // Instead repeating 0, we repeat MSB : 1000_1000 >> 2 = 1110_0010 (MSB Is 1)
                outdata = $signed(indata1) >>> indata2[4:0];
            `opcode_alu_slt :
                // set if less than 
                begin
                if ($signed(indata1) < $signed(indata2)) begin
                    outdata =   32'd1 ; 
                end
            end
            `opcode_alu_sltu : begin // set if less than usigned 
                if (indata1 < indata2) begin
                    outdata =  32'd1 ;
                end
            end                
            `opcode_alu_xor : outdata = indata1 ^ indata2;
            `opcode_alu_or : outdata = indata1 | indata2 ;
            `opcode_alu_and : outdata = indata1 & indata2 ; 
            default : flag_bus[`WORD-1] = 1'b1; // invalid opcode
        endcase
    end 
end
endmodule
