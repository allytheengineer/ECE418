set moduleName prep_Pipeline_VITIS_LOOP_275_2
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {prep_Pipeline_VITIS_LOOP_275_2}
set C_modelType { void 0 }
set C_modelArgList {
	{ tmp_2 int 9 regular  }
	{ add_ln276_1 int 17 regular  }
	{ messageBlocks int 5 regular {array 65664 { 1 3 } 1 1 }  }
	{ splitBlock int 5 regular {array 33 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "tmp_2", "interface" : "wire", "bitwidth" : 9, "direction" : "READONLY"} , 
 	{ "Name" : "add_ln276_1", "interface" : "wire", "bitwidth" : 17, "direction" : "READONLY"} , 
 	{ "Name" : "messageBlocks", "interface" : "memory", "bitwidth" : 5, "direction" : "READONLY"} , 
 	{ "Name" : "splitBlock", "interface" : "memory", "bitwidth" : 5, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 15
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ tmp_2 sc_in sc_lv 9 signal 0 } 
	{ add_ln276_1 sc_in sc_lv 17 signal 1 } 
	{ messageBlocks_address0 sc_out sc_lv 17 signal 2 } 
	{ messageBlocks_ce0 sc_out sc_logic 1 signal 2 } 
	{ messageBlocks_q0 sc_in sc_lv 5 signal 2 } 
	{ splitBlock_address0 sc_out sc_lv 6 signal 3 } 
	{ splitBlock_ce0 sc_out sc_logic 1 signal 3 } 
	{ splitBlock_we0 sc_out sc_logic 1 signal 3 } 
	{ splitBlock_d0 sc_out sc_lv 5 signal 3 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "tmp_2", "direction": "in", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "tmp_2", "role": "default" }} , 
 	{ "name": "add_ln276_1", "direction": "in", "datatype": "sc_lv", "bitwidth":17, "type": "signal", "bundle":{"name": "add_ln276_1", "role": "default" }} , 
 	{ "name": "messageBlocks_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":17, "type": "signal", "bundle":{"name": "messageBlocks", "role": "address0" }} , 
 	{ "name": "messageBlocks_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "messageBlocks", "role": "ce0" }} , 
 	{ "name": "messageBlocks_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "messageBlocks", "role": "q0" }} , 
 	{ "name": "splitBlock_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "splitBlock", "role": "address0" }} , 
 	{ "name": "splitBlock_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "splitBlock", "role": "ce0" }} , 
 	{ "name": "splitBlock_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "splitBlock", "role": "we0" }} , 
 	{ "name": "splitBlock_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "splitBlock", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "prep_Pipeline_VITIS_LOOP_275_2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "35", "EstimateLatencyMax" : "35",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "tmp_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "add_ln276_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "messageBlocks", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "splitBlock", "Type" : "Memory", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_275_2", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter2", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter2", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	prep_Pipeline_VITIS_LOOP_275_2 {
		tmp_2 {Type I LastRead 0 FirstWrite -1}
		add_ln276_1 {Type I LastRead 0 FirstWrite -1}
		messageBlocks {Type I LastRead 1 FirstWrite -1}
		splitBlock {Type O LastRead -1 FirstWrite 2}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "35", "Max" : "35"}
	, {"Name" : "Interval", "Min" : "35", "Max" : "35"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	tmp_2 { ap_none {  { tmp_2 in_data 0 9 } } }
	add_ln276_1 { ap_none {  { add_ln276_1 in_data 0 17 } } }
	messageBlocks { ap_memory {  { messageBlocks_address0 mem_address 1 17 }  { messageBlocks_ce0 mem_ce 1 1 }  { messageBlocks_q0 in_data 0 5 } } }
	splitBlock { ap_memory {  { splitBlock_address0 mem_address 1 6 }  { splitBlock_ce0 mem_ce 1 1 }  { splitBlock_we0 mem_we 1 1 }  { splitBlock_d0 mem_din 1 5 } } }
}
