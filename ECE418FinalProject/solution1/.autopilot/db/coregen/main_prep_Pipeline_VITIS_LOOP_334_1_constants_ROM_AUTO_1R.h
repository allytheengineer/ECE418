// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R_H__
#define __main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 64;
  static const unsigned AddressWidth = 6;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R_ram) {
        ram[0] = "0b01000010100010100010111110011000";
        ram[1] = "0b01110001001101110100010010010001";
        ram[2] = "0b10110101110000001111101111001111";
        ram[3] = "0b11101001101101011101101110100101";
        ram[4] = "0b00111001010101101100001001011011";
        ram[5] = "0b01011001111100010001000111110001";
        ram[6] = "0b10010010001111111000001010100100";
        ram[7] = "0b10101011000111000101111011010101";
        ram[8] = "0b11011000000001111010101010011000";
        ram[9] = "0b00010010100000110101101100000001";
        ram[10] = "0b00100100001100011000010110111110";
        ram[11] = "0b01010101000011000111110111000011";
        ram[12] = "0b01110010101111100101110101110100";
        ram[13] = "0b10000000110111101011000111111110";
        ram[14] = "0b10011011110111000000011010100111";
        ram[15] = "0b11000001100110111111000101110100";
        ram[16] = "0b11100100100110110110100111000001";
        ram[17] = "0b11101111101111100100011110000110";
        ram[18] = "0b00001111110000011001110111000110";
        ram[19] = "0b00100100000011001010000111001100";
        ram[20] = "0b00101101111010010010110001101111";
        ram[21] = "0b01001010011101001000010010101010";
        ram[22] = "0b01011100101100001010100111011100";
        ram[23] = "0b01110110111110011000100011011010";
        ram[24] = "0b10011000001111100101000101010010";
        ram[25] = "0b10101000001100011100011001101101";
        ram[26] = "0b10110000000000110010011111001000";
        ram[27] = "0b10111111010110010111111111000111";
        ram[28] = "0b11000110111000000000101111110011";
        ram[29] = "0b11010101101001111001000101000111";
        ram[30] = "0b00000110110010100110001101010001";
        ram[31] = "0b00010100001010010010100101100111";
        ram[32] = "0b00100111101101110000101010000101";
        ram[33] = "0b00101110000110110010000100111000";
        ram[34] = "0b01001101001011000110110111111100";
        ram[35] = "0b01010011001110000000110100010011";
        ram[36] = "0b01100101000010100111001101010100";
        ram[37] = "0b01110110011010100000101010111011";
        ram[38] = "0b10000001110000101100100100101110";
        ram[39] = "0b10010010011100100010110010000101";
        ram[40] = "0b10100010101111111110100010100001";
        ram[41] = "0b10101000000110100110011001001011";
        ram[42] = "0b11000010010010111000101101110000";
        ram[43] = "0b11000111011011000101000110100011";
        ram[44] = "0b11010001100100101110100000011001";
        ram[45] = "0b11010110100110010000011000100100";
        ram[46] = "0b11110100000011100011010110000101";
        ram[47] = "0b00010000011010101010000001110000";
        ram[48] = "0b00011001101001001100000100010110";
        ram[49] = "0b00011110001101110110110000001000";
        ram[50] = "0b00100111010010000111011101001100";
        ram[51] = "0b00110100101100001011110010110101";
        ram[52] = "0b00111001000111000000110010110011";
        ram[53] = "0b01001110110110001010101001001010";
        ram[54] = "0b01011011100111001100101001001111";
        ram[55] = "0b01101000001011100110111111110011";
        ram[56] = "0b01110100100011111000001011101110";
        ram[57] = "0b01111000101001010110001101101111";
        ram[58] = "0b10000100110010000111100000010100";
        ram[59] = "0b10001100110001110000001000001000";
        ram[60] = "0b10010000101111101111111111111010";
        ram[61] = "0b10100100010100000110110011101011";
        ram[62] = "0b10111110111110011010001111110111";
        ram[63] = "0b11000110011100010111100011110010";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 64;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R_ram* meminst;


SC_CTOR(main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R) {
meminst = new main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R_ram("main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R() {
    delete meminst;
}


};//endmodule
#endif
