# This script segment is generated automatically by AutoPilot

# Memory (RAM/ROM)  definition:
set ID 26
set hasByteEnable 0
set MemName main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R
set CoreName ap_simcore_mem
set PortList { 1 }
set DataWd 32
set AddrRange 64
set AddrWd 6
set impl_style auto
set TrueReset 0
set IsROM 1
set ROMData { "01000010100010100010111110011000" "01110001001101110100010010010001" "10110101110000001111101111001111" "11101001101101011101101110100101" "00111001010101101100001001011011" "01011001111100010001000111110001" "10010010001111111000001010100100" "10101011000111000101111011010101" "11011000000001111010101010011000" "00010010100000110101101100000001" "00100100001100011000010110111110" "01010101000011000111110111000011" "01110010101111100101110101110100" "10000000110111101011000111111110" "10011011110111000000011010100111" "11000001100110111111000101110100" "11100100100110110110100111000001" "11101111101111100100011110000110" "00001111110000011001110111000110" "00100100000011001010000111001100" "00101101111010010010110001101111" "01001010011101001000010010101010" "01011100101100001010100111011100" "01110110111110011000100011011010" "10011000001111100101000101010010" "10101000001100011100011001101101" "10110000000000110010011111001000" "10111111010110010111111111000111" "11000110111000000000101111110011" "11010101101001111001000101000111" "00000110110010100110001101010001" "00010100001010010010100101100111" "00100111101101110000101010000101" "00101110000110110010000100111000" "01001101001011000110110111111100" "01010011001110000000110100010011" "01100101000010100111001101010100" "01110110011010100000101010111011" "10000001110000101100100100101110" "10010010011100100010110010000101" "10100010101111111110100010100001" "10101000000110100110011001001011" "11000010010010111000101101110000" "11000111011011000101000110100011" "11010001100100101110100000011001" "11010110100110010000011000100100" "11110100000011100011010110000101" "00010000011010101010000001110000" "00011001101001001100000100010110" "00011110001101110110110000001000" "00100111010010000111011101001100" "00110100101100001011110010110101" "00111001000111000000110010110011" "01001110110110001010101001001010" "01011011100111001100101001001111" "01101000001011100110111111110011" "01110100100011111000001011101110" "01111000101001010110001101101111" "10000100110010000111100000010100" "10001100110001110000001000001000" "10010000101111101111111111111010" "10100100010100000110110011101011" "10111110111110011010001111110111" "11000110011100010111100011110010" }
set HasInitializer 1
set Initializer $ROMData
set NumOfStage 2
set DelayBudget 3.257
set ClkPeriod 10
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mem] == "ap_gen_simcore_mem"} {
    eval "ap_gen_simcore_mem { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem  \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    port_num 1 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
} else {
    puts "@W \[IMPL-102\] Cannot find ap_gen_simcore_mem, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $MemName BINDTYPE {storage} TYPE {rom} IMPL {auto} LATENCY 2 ALLOW_PRAGMA 1
}


set CoreName ROM
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_ROM] == "::AESL_LIB_VIRTEX::xil_gen_ROM"} {
    eval "::AESL_LIB_VIRTEX::xil_gen_ROM { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem  \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    port_num 1 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
  } else {
    puts "@W \[IMPL-104\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_ROM, check your platform lib"
  }
}


# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 35 \
    name messageSchedule \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename messageSchedule \
    op interface \
    ports { messageSchedule_address0 { O 6 vector } messageSchedule_ce0 { O 1 bit } messageSchedule_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'messageSchedule'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 27 \
    name empty_12 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_empty_12 \
    op interface \
    ports { empty_12 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 28 \
    name empty_13 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_empty_13 \
    op interface \
    ports { empty_13 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 29 \
    name empty_14 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_empty_14 \
    op interface \
    ports { empty_14 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 30 \
    name empty_15 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_empty_15 \
    op interface \
    ports { empty_15 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 31 \
    name empty_16 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_empty_16 \
    op interface \
    ports { empty_16 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 32 \
    name empty_17 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_empty_17 \
    op interface \
    ports { empty_17 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 33 \
    name empty_18 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_empty_18 \
    op interface \
    ports { empty_18 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 34 \
    name empty \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_empty \
    op interface \
    ports { empty { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 36 \
    name add186789_i_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_add186789_i_out \
    op interface \
    ports { add186789_i_out { O 32 vector } add186789_i_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 37 \
    name z_assign_1_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_z_assign_1_out \
    op interface \
    ports { z_assign_1_out { O 32 vector } z_assign_1_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 38 \
    name y_assign_1_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_y_assign_1_out \
    op interface \
    ports { y_assign_1_out { O 32 vector } y_assign_1_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 39 \
    name x_assign_3_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_x_assign_3_out \
    op interface \
    ports { x_assign_3_out { O 32 vector } x_assign_3_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 40 \
    name add172345_i_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_add172345_i_out \
    op interface \
    ports { add172345_i_out { O 32 vector } add172345_i_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 41 \
    name z_assign_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_z_assign_out \
    op interface \
    ports { z_assign_out { O 32 vector } z_assign_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 42 \
    name y_assign_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_y_assign_out \
    op interface \
    ports { y_assign_out { O 32 vector } y_assign_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 43 \
    name x_assign_2_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_x_assign_2_out \
    op interface \
    ports { x_assign_2_out { O 32 vector } x_assign_2_out_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -2 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


# flow_control definition:
set InstName main_flow_control_loop_pipe_sequential_init_U
set CompName main_flow_control_loop_pipe_sequential_init
set name flow_control_loop_pipe_sequential_init
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control] == "::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control"} {
eval "::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control { \
    name ${name} \
    prefix main_ \
}"
} else {
puts "@W \[IMPL-107\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $CompName BINDTYPE interface TYPE internal_upc_flow_control INSTNAME $InstName
}


