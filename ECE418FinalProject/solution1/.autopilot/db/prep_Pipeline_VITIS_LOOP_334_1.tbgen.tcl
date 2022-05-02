set moduleName prep_Pipeline_VITIS_LOOP_334_1
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
set C_modelName {prep_Pipeline_VITIS_LOOP_334_1}
set C_modelType { void 0 }
set C_modelArgList {
	{ empty_12 int 32 regular  }
	{ empty_13 int 32 regular  }
	{ empty_14 int 32 regular  }
	{ empty_15 int 32 regular  }
	{ empty_16 int 32 regular  }
	{ empty_17 int 32 regular  }
	{ empty_18 int 32 regular  }
	{ empty int 32 regular  }
	{ messageSchedule int 32 regular {array 64 { 1 3 } 1 1 }  }
	{ add186789_i_out int 32 regular {pointer 1}  }
	{ z_assign_1_out int 32 regular {pointer 1}  }
	{ y_assign_1_out int 32 regular {pointer 1}  }
	{ x_assign_3_out int 32 regular {pointer 1}  }
	{ add172345_i_out int 32 regular {pointer 1}  }
	{ z_assign_out int 32 regular {pointer 1}  }
	{ y_assign_out int 32 regular {pointer 1}  }
	{ x_assign_2_out int 32 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "empty_12", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "empty_13", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "empty_14", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "empty_15", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "empty_16", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "empty_17", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "empty_18", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "empty", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "messageSchedule", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "add186789_i_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "z_assign_1_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "y_assign_1_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "x_assign_3_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "add172345_i_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "z_assign_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "y_assign_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "x_assign_2_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 33
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ empty_12 sc_in sc_lv 32 signal 0 } 
	{ empty_13 sc_in sc_lv 32 signal 1 } 
	{ empty_14 sc_in sc_lv 32 signal 2 } 
	{ empty_15 sc_in sc_lv 32 signal 3 } 
	{ empty_16 sc_in sc_lv 32 signal 4 } 
	{ empty_17 sc_in sc_lv 32 signal 5 } 
	{ empty_18 sc_in sc_lv 32 signal 6 } 
	{ empty sc_in sc_lv 32 signal 7 } 
	{ messageSchedule_address0 sc_out sc_lv 6 signal 8 } 
	{ messageSchedule_ce0 sc_out sc_logic 1 signal 8 } 
	{ messageSchedule_q0 sc_in sc_lv 32 signal 8 } 
	{ add186789_i_out sc_out sc_lv 32 signal 9 } 
	{ add186789_i_out_ap_vld sc_out sc_logic 1 outvld 9 } 
	{ z_assign_1_out sc_out sc_lv 32 signal 10 } 
	{ z_assign_1_out_ap_vld sc_out sc_logic 1 outvld 10 } 
	{ y_assign_1_out sc_out sc_lv 32 signal 11 } 
	{ y_assign_1_out_ap_vld sc_out sc_logic 1 outvld 11 } 
	{ x_assign_3_out sc_out sc_lv 32 signal 12 } 
	{ x_assign_3_out_ap_vld sc_out sc_logic 1 outvld 12 } 
	{ add172345_i_out sc_out sc_lv 32 signal 13 } 
	{ add172345_i_out_ap_vld sc_out sc_logic 1 outvld 13 } 
	{ z_assign_out sc_out sc_lv 32 signal 14 } 
	{ z_assign_out_ap_vld sc_out sc_logic 1 outvld 14 } 
	{ y_assign_out sc_out sc_lv 32 signal 15 } 
	{ y_assign_out_ap_vld sc_out sc_logic 1 outvld 15 } 
	{ x_assign_2_out sc_out sc_lv 32 signal 16 } 
	{ x_assign_2_out_ap_vld sc_out sc_logic 1 outvld 16 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "empty_12", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "empty_12", "role": "default" }} , 
 	{ "name": "empty_13", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "empty_13", "role": "default" }} , 
 	{ "name": "empty_14", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "empty_14", "role": "default" }} , 
 	{ "name": "empty_15", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "empty_15", "role": "default" }} , 
 	{ "name": "empty_16", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "empty_16", "role": "default" }} , 
 	{ "name": "empty_17", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "empty_17", "role": "default" }} , 
 	{ "name": "empty_18", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "empty_18", "role": "default" }} , 
 	{ "name": "empty", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "empty", "role": "default" }} , 
 	{ "name": "messageSchedule_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "messageSchedule", "role": "address0" }} , 
 	{ "name": "messageSchedule_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "messageSchedule", "role": "ce0" }} , 
 	{ "name": "messageSchedule_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "messageSchedule", "role": "q0" }} , 
 	{ "name": "add186789_i_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "add186789_i_out", "role": "default" }} , 
 	{ "name": "add186789_i_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "add186789_i_out", "role": "ap_vld" }} , 
 	{ "name": "z_assign_1_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "z_assign_1_out", "role": "default" }} , 
 	{ "name": "z_assign_1_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "z_assign_1_out", "role": "ap_vld" }} , 
 	{ "name": "y_assign_1_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "y_assign_1_out", "role": "default" }} , 
 	{ "name": "y_assign_1_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "y_assign_1_out", "role": "ap_vld" }} , 
 	{ "name": "x_assign_3_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "x_assign_3_out", "role": "default" }} , 
 	{ "name": "x_assign_3_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "x_assign_3_out", "role": "ap_vld" }} , 
 	{ "name": "add172345_i_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "add172345_i_out", "role": "default" }} , 
 	{ "name": "add172345_i_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "add172345_i_out", "role": "ap_vld" }} , 
 	{ "name": "z_assign_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "z_assign_out", "role": "default" }} , 
 	{ "name": "z_assign_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "z_assign_out", "role": "ap_vld" }} , 
 	{ "name": "y_assign_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "y_assign_out", "role": "default" }} , 
 	{ "name": "y_assign_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "y_assign_out", "role": "ap_vld" }} , 
 	{ "name": "x_assign_2_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "x_assign_2_out", "role": "default" }} , 
 	{ "name": "x_assign_2_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "x_assign_2_out", "role": "ap_vld" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
		"CDFG" : "prep_Pipeline_VITIS_LOOP_334_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "70", "EstimateLatencyMax" : "70",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "empty_12", "Type" : "None", "Direction" : "I"},
			{"Name" : "empty_13", "Type" : "None", "Direction" : "I"},
			{"Name" : "empty_14", "Type" : "None", "Direction" : "I"},
			{"Name" : "empty_15", "Type" : "None", "Direction" : "I"},
			{"Name" : "empty_16", "Type" : "None", "Direction" : "I"},
			{"Name" : "empty_17", "Type" : "None", "Direction" : "I"},
			{"Name" : "empty_18", "Type" : "None", "Direction" : "I"},
			{"Name" : "empty", "Type" : "None", "Direction" : "I"},
			{"Name" : "messageSchedule", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "add186789_i_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "z_assign_1_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "y_assign_1_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "x_assign_3_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "add172345_i_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "z_assign_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "y_assign_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "x_assign_2_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "constants", "Type" : "Memory", "Direction" : "I"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_334_1", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter4", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter4", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.constants_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	prep_Pipeline_VITIS_LOOP_334_1 {
		empty_12 {Type I LastRead 0 FirstWrite -1}
		empty_13 {Type I LastRead 0 FirstWrite -1}
		empty_14 {Type I LastRead 0 FirstWrite -1}
		empty_15 {Type I LastRead 0 FirstWrite -1}
		empty_16 {Type I LastRead 0 FirstWrite -1}
		empty_17 {Type I LastRead 0 FirstWrite -1}
		empty_18 {Type I LastRead 0 FirstWrite -1}
		empty {Type I LastRead 0 FirstWrite -1}
		messageSchedule {Type I LastRead 0 FirstWrite -1}
		add186789_i_out {Type O LastRead -1 FirstWrite 4}
		z_assign_1_out {Type O LastRead -1 FirstWrite 4}
		y_assign_1_out {Type O LastRead -1 FirstWrite 4}
		x_assign_3_out {Type O LastRead -1 FirstWrite 4}
		add172345_i_out {Type O LastRead -1 FirstWrite 4}
		z_assign_out {Type O LastRead -1 FirstWrite 4}
		y_assign_out {Type O LastRead -1 FirstWrite 4}
		x_assign_2_out {Type O LastRead -1 FirstWrite 4}
		constants {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "70", "Max" : "70"}
	, {"Name" : "Interval", "Min" : "70", "Max" : "70"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	empty_12 { ap_none {  { empty_12 in_data 0 32 } } }
	empty_13 { ap_none {  { empty_13 in_data 0 32 } } }
	empty_14 { ap_none {  { empty_14 in_data 0 32 } } }
	empty_15 { ap_none {  { empty_15 in_data 0 32 } } }
	empty_16 { ap_none {  { empty_16 in_data 0 32 } } }
	empty_17 { ap_none {  { empty_17 in_data 0 32 } } }
	empty_18 { ap_none {  { empty_18 in_data 0 32 } } }
	empty { ap_none {  { empty in_data 0 32 } } }
	messageSchedule { ap_memory {  { messageSchedule_address0 mem_address 1 6 }  { messageSchedule_ce0 mem_ce 1 1 }  { messageSchedule_q0 mem_dout 0 32 } } }
	add186789_i_out { ap_vld {  { add186789_i_out out_data 1 32 }  { add186789_i_out_ap_vld out_vld 1 1 } } }
	z_assign_1_out { ap_vld {  { z_assign_1_out out_data 1 32 }  { z_assign_1_out_ap_vld out_vld 1 1 } } }
	y_assign_1_out { ap_vld {  { y_assign_1_out out_data 1 32 }  { y_assign_1_out_ap_vld out_vld 1 1 } } }
	x_assign_3_out { ap_vld {  { x_assign_3_out out_data 1 32 }  { x_assign_3_out_ap_vld out_vld 1 1 } } }
	add172345_i_out { ap_vld {  { add172345_i_out out_data 1 32 }  { add172345_i_out_ap_vld out_vld 1 1 } } }
	z_assign_out { ap_vld {  { z_assign_out out_data 1 32 }  { z_assign_out_ap_vld out_vld 1 1 } } }
	y_assign_out { ap_vld {  { y_assign_out out_data 1 32 }  { y_assign_out_ap_vld out_vld 1 1 } } }
	x_assign_2_out { ap_vld {  { x_assign_2_out out_data 1 32 }  { x_assign_2_out_ap_vld out_vld 1 1 } } }
}
