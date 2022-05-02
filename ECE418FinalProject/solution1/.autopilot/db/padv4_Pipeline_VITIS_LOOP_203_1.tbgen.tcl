set moduleName padv4_Pipeline_VITIS_LOOP_203_1
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
set C_modelName {padv4_Pipeline_VITIS_LOOP_203_1}
set C_modelType { void 0 }
set C_modelArgList {
	{ sizeNeeded_3_reload int 32 regular  }
	{ sizeNeeded_out int 32 regular {pointer 1}  }
	{ p_cond_out int 1 regular {pointer 1}  }
	{ sub_ln203_out int 32 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "sizeNeeded_3_reload", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "sizeNeeded_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "p_cond_out", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY"} , 
 	{ "Name" : "sub_ln203_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 13
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ sizeNeeded_3_reload sc_in sc_lv 32 signal 0 } 
	{ sizeNeeded_out sc_out sc_lv 32 signal 1 } 
	{ sizeNeeded_out_ap_vld sc_out sc_logic 1 outvld 1 } 
	{ p_cond_out sc_out sc_lv 1 signal 2 } 
	{ p_cond_out_ap_vld sc_out sc_logic 1 outvld 2 } 
	{ sub_ln203_out sc_out sc_lv 32 signal 3 } 
	{ sub_ln203_out_ap_vld sc_out sc_logic 1 outvld 3 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "sizeNeeded_3_reload", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "sizeNeeded_3_reload", "role": "default" }} , 
 	{ "name": "sizeNeeded_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "sizeNeeded_out", "role": "default" }} , 
 	{ "name": "sizeNeeded_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "sizeNeeded_out", "role": "ap_vld" }} , 
 	{ "name": "p_cond_out", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "p_cond_out", "role": "default" }} , 
 	{ "name": "p_cond_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "p_cond_out", "role": "ap_vld" }} , 
 	{ "name": "sub_ln203_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "sub_ln203_out", "role": "default" }} , 
 	{ "name": "sub_ln203_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "sub_ln203_out", "role": "ap_vld" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "padv4_Pipeline_VITIS_LOOP_203_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "sizeNeeded_3_reload", "Type" : "None", "Direction" : "I"},
			{"Name" : "sizeNeeded_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "p_cond_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "sub_ln203_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_203_1", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter1", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter0", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	padv4_Pipeline_VITIS_LOOP_203_1 {
		sizeNeeded_3_reload {Type I LastRead 0 FirstWrite -1}
		sizeNeeded_out {Type O LastRead -1 FirstWrite 0}
		p_cond_out {Type O LastRead -1 FirstWrite 0}
		sub_ln203_out {Type O LastRead -1 FirstWrite 0}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	sizeNeeded_3_reload { ap_none {  { sizeNeeded_3_reload in_data 0 32 } } }
	sizeNeeded_out { ap_vld {  { sizeNeeded_out out_data 1 32 }  { sizeNeeded_out_ap_vld out_vld 1 1 } } }
	p_cond_out { ap_vld {  { p_cond_out out_data 1 1 }  { p_cond_out_ap_vld out_vld 1 1 } } }
	sub_ln203_out { ap_vld {  { sub_ln203_out out_data 1 32 }  { sub_ln203_out_ap_vld out_vld 1 1 } } }
}
