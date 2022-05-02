set SynModuleInfo {
  {SRCNAME padv4_Pipeline_VITIS_LOOP_10_1 MODELNAME padv4_Pipeline_VITIS_LOOP_10_1 RTLNAME main_padv4_Pipeline_VITIS_LOOP_10_1
    SUBMODULES {
      {MODELNAME main_flow_control_loop_pipe_sequential_init RTLNAME main_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME main_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME padv4_Pipeline_VITIS_LOOP_203_1 MODELNAME padv4_Pipeline_VITIS_LOOP_203_1 RTLNAME main_padv4_Pipeline_VITIS_LOOP_203_1}
  {SRCNAME padv4_Pipeline_VITIS_LOOP_209_2 MODELNAME padv4_Pipeline_VITIS_LOOP_209_2 RTLNAME main_padv4_Pipeline_VITIS_LOOP_209_2}
  {SRCNAME padv4_Pipeline_VITIS_LOOP_215_3 MODELNAME padv4_Pipeline_VITIS_LOOP_215_3 RTLNAME main_padv4_Pipeline_VITIS_LOOP_215_3}
  {SRCNAME padv4_Pipeline_VITIS_LOOP_223_4 MODELNAME padv4_Pipeline_VITIS_LOOP_223_4 RTLNAME main_padv4_Pipeline_VITIS_LOOP_223_4
    SUBMODULES {
      {MODELNAME main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R RTLNAME main_padv4_Pipeline_VITIS_LOOP_223_4_messageLengthInBinary2_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME padv4 MODELNAME padv4 RTLNAME main_padv4
    SUBMODULES {
      {MODELNAME main_padv4_message5binary_ROM_AUTO_1R RTLNAME main_padv4_message5binary_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME prep_Pipeline_VITIS_LOOP_275_2 MODELNAME prep_Pipeline_VITIS_LOOP_275_2 RTLNAME main_prep_Pipeline_VITIS_LOOP_275_2}
  {SRCNAME prep_Pipeline_VITIS_LOOP_243_1 MODELNAME prep_Pipeline_VITIS_LOOP_243_1 RTLNAME main_prep_Pipeline_VITIS_LOOP_243_1}
  {SRCNAME prep_Pipeline_VITIS_LOOP_285_3 MODELNAME prep_Pipeline_VITIS_LOOP_285_3 RTLNAME main_prep_Pipeline_VITIS_LOOP_285_3}
  {SRCNAME prep_Pipeline_VITIS_LOOP_292_4 MODELNAME prep_Pipeline_VITIS_LOOP_292_4 RTLNAME main_prep_Pipeline_VITIS_LOOP_292_4}
  {SRCNAME prep_Pipeline_VITIS_LOOP_334_1 MODELNAME prep_Pipeline_VITIS_LOOP_334_1 RTLNAME main_prep_Pipeline_VITIS_LOOP_334_1
    SUBMODULES {
      {MODELNAME main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R RTLNAME main_prep_Pipeline_VITIS_LOOP_334_1_constants_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME prep MODELNAME prep RTLNAME main_prep
    SUBMODULES {
      {MODELNAME main_prep_hash_RAM_AUTO_1R1W RTLNAME main_prep_hash_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME main_prep_splitBlock_RAM_AUTO_1R1W RTLNAME main_prep_splitBlock_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME main_prep_messageBlocks_RAM_AUTO_1R1W RTLNAME main_prep_messageBlocks_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME main_prep_messageSchedule_RAM_AUTO_1R1W RTLNAME main_prep_messageSchedule_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME main MODELNAME main RTLNAME main IS_TOP 1}
}
