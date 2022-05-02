// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R_H__
#define __main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 5;
  static const unsigned AddressRange = 65;
  static const unsigned AddressWidth = 7;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R_ram) {
        for (unsigned i = 0; i < 52 ; i = i + 1) {
            ram[i] = "0b10000";
        }
        ram[52] = "0b10001";
        ram[53] = "0b10000";
        ram[54] = "0b10001";
        ram[55] = "0b10000";
        ram[56] = "0b10000";
        ram[57] = "0b10000";
        ram[58] = "0b10001";
        ram[59] = "0b10001";
        ram[60] = "0b10001";
        ram[61] = "0b10000";
        ram[62] = "0b10000";
        ram[63] = "0b10000";
        ram[64] = "0b00000";


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


SC_MODULE(main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R) {


static const unsigned DataWidth = 5;
static const unsigned AddressRange = 65;
static const unsigned AddressWidth = 7;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R_ram* meminst;


SC_CTOR(main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R) {
meminst = new main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R_ram("main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R() {
    delete meminst;
}


};//endmodule
#endif
