############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project ECE418FinalProject
add_files ECE418FinalProject/padding.c
open_solution "solution1" -flow_target vivado
set_part {xc7a100tcsg324-1}
create_clock -period 10 -name default
#source "./ECE418FinalProject/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog