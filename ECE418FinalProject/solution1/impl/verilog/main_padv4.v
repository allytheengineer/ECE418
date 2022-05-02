// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Version: 2021.2
// Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module main_padv4 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        messageBlocks_address0,
        messageBlocks_ce0,
        messageBlocks_we0,
        messageBlocks_d0,
        ap_return
);

parameter    ap_ST_fsm_state1 = 8'd1;
parameter    ap_ST_fsm_state2 = 8'd2;
parameter    ap_ST_fsm_state3 = 8'd4;
parameter    ap_ST_fsm_state4 = 8'd8;
parameter    ap_ST_fsm_state5 = 8'd16;
parameter    ap_ST_fsm_state6 = 8'd32;
parameter    ap_ST_fsm_state7 = 8'd64;
parameter    ap_ST_fsm_state8 = 8'd128;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [16:0] messageBlocks_address0;
output   messageBlocks_ce0;
output   messageBlocks_we0;
output  [4:0] messageBlocks_d0;
output  [24:0] ap_return;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg[16:0] messageBlocks_address0;
reg messageBlocks_ce0;
reg messageBlocks_we0;
reg[4:0] messageBlocks_d0;

(* fsm_encoding = "none" *) reg   [7:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire  signed [23:0] select_ln207_fu_149_p3;
reg  signed [23:0] select_ln207_reg_217;
wire    ap_CS_fsm_state6;
wire   [16:0] add_ln224_fu_173_p2;
reg   [16:0] add_ln224_reg_222;
wire    grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_start;
wire    grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_done;
wire    grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_idle;
wire    grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_ready;
wire   [31:0] grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_sizeNeeded_out;
wire    grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_sizeNeeded_out_ap_vld;
wire   [0:0] grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_p_cond_out;
wire    grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_p_cond_out_ap_vld;
wire   [31:0] grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_sub_ln203_out;
wire    grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_sub_ln203_out_ap_vld;
wire    grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_start;
wire    grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_done;
wire    grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_idle;
wire    grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_ready;
wire   [16:0] grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_address0;
wire    grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_ce0;
wire    grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_we0;
wire   [4:0] grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_d0;
wire    grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_start;
wire    grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_done;
wire    grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_idle;
wire    grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_ready;
wire   [16:0] grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_address0;
wire    grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_ce0;
wire    grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_we0;
wire   [4:0] grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_d0;
wire    grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_start;
wire    grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_done;
wire    grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_idle;
wire    grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_ready;
wire   [16:0] grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_address0;
wire    grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_ce0;
wire    grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_we0;
wire   [4:0] grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_d0;
reg    grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_start_reg;
wire    ap_CS_fsm_state2;
reg   [0:0] p_cond_loc_fu_44;
reg   [31:0] sub_ln203_loc_fu_40;
reg    grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_start_reg;
reg    grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_start_reg;
wire    ap_CS_fsm_state4;
wire    ap_CS_fsm_state5;
reg    grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_start_reg;
wire    ap_CS_fsm_state7;
wire    ap_CS_fsm_state3;
wire   [63:0] zext_ln226_fu_194_p1;
wire    ap_CS_fsm_state8;
wire   [22:0] trunc_ln207_1_fu_115_p4;
wire   [23:0] zext_ln207_fu_125_p1;
wire   [22:0] trunc_ln207_2_fu_135_p4;
wire   [23:0] sub_ln207_fu_129_p2;
wire   [23:0] zext_ln207_1_fu_145_p1;
wire   [7:0] trunc_ln224_1_fu_161_p1;
wire   [16:0] tmp_19_cast_fu_165_p3;
wire   [16:0] trunc_ln224_fu_157_p1;
wire  signed [24:0] sext_ln207_fu_180_p1;
wire   [16:0] add_ln226_fu_189_p2;
reg   [7:0] ap_NS_fsm;
reg    ap_ST_fsm_state1_blk;
reg    ap_block_state2_on_subcall_done;
reg    ap_ST_fsm_state2_blk;
wire    ap_ST_fsm_state3_blk;
wire    ap_ST_fsm_state4_blk;
reg    ap_ST_fsm_state5_blk;
wire    ap_ST_fsm_state6_blk;
reg    ap_ST_fsm_state7_blk;
wire    ap_ST_fsm_state8_blk;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 8'd1;
#0 grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_start_reg = 1'b0;
#0 grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_start_reg = 1'b0;
#0 grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_start_reg = 1'b0;
#0 grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_start_reg = 1'b0;
end

main_padv4_Pipeline_VITIS_LOOP_203_1 grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_start),
    .ap_done(grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_done),
    .ap_idle(grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_idle),
    .ap_ready(grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_ready),
    .sizeNeeded_out(grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_sizeNeeded_out),
    .sizeNeeded_out_ap_vld(grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_sizeNeeded_out_ap_vld),
    .p_cond_out(grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_p_cond_out),
    .p_cond_out_ap_vld(grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_p_cond_out_ap_vld),
    .sub_ln203_out(grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_sub_ln203_out),
    .sub_ln203_out_ap_vld(grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_sub_ln203_out_ap_vld)
);

main_padv4_Pipeline_VITIS_LOOP_209_2 grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_start),
    .ap_done(grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_done),
    .ap_idle(grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_idle),
    .ap_ready(grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_ready),
    .messageBlocks_address0(grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_address0),
    .messageBlocks_ce0(grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_ce0),
    .messageBlocks_we0(grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_we0),
    .messageBlocks_d0(grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_d0)
);

main_padv4_Pipeline_VITIS_LOOP_215_3 grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_start),
    .ap_done(grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_done),
    .ap_idle(grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_idle),
    .ap_ready(grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_ready),
    .messageBlocks_address0(grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_address0),
    .messageBlocks_ce0(grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_ce0),
    .messageBlocks_we0(grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_we0),
    .messageBlocks_d0(grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_d0)
);

main_padv4_Pipeline_VITIS_LOOP_223_4 grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_start),
    .ap_done(grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_done),
    .ap_idle(grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_idle),
    .ap_ready(grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_ready),
    .add_ln224(add_ln224_reg_222),
    .messageBlocks_address0(grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_address0),
    .messageBlocks_ce0(grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_ce0),
    .messageBlocks_we0(grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_we0),
    .messageBlocks_d0(grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_d0)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_start_reg <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
            grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_start_reg <= 1'b1;
        end else if ((grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_ready == 1'b1)) begin
            grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_start_reg <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
            grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_start_reg <= 1'b1;
        end else if ((grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_ready == 1'b1)) begin
            grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_start_reg <= 1'b0;
    end else begin
        if ((1'b1 == ap_CS_fsm_state4)) begin
            grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_start_reg <= 1'b1;
        end else if ((grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_ready == 1'b1)) begin
            grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_start_reg <= 1'b0;
    end else begin
        if ((1'b1 == ap_CS_fsm_state6)) begin
            grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_start_reg <= 1'b1;
        end else if ((grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_ready == 1'b1)) begin
            grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state6)) begin
        add_ln224_reg_222 <= add_ln224_fu_173_p2;
        select_ln207_reg_217 <= select_ln207_fu_149_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_p_cond_out_ap_vld == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
        p_cond_loc_fu_44 <= grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_p_cond_out;
    end
end

always @ (posedge ap_clk) begin
    if (((grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_sub_ln203_out_ap_vld == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
        sub_ln203_loc_fu_40 <= grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_sub_ln203_out;
    end
end

always @ (*) begin
    if ((ap_start == 1'b0)) begin
        ap_ST_fsm_state1_blk = 1'b1;
    end else begin
        ap_ST_fsm_state1_blk = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_block_state2_on_subcall_done)) begin
        ap_ST_fsm_state2_blk = 1'b1;
    end else begin
        ap_ST_fsm_state2_blk = 1'b0;
    end
end

assign ap_ST_fsm_state3_blk = 1'b0;

assign ap_ST_fsm_state4_blk = 1'b0;

always @ (*) begin
    if ((grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_done == 1'b0)) begin
        ap_ST_fsm_state5_blk = 1'b1;
    end else begin
        ap_ST_fsm_state5_blk = 1'b0;
    end
end

assign ap_ST_fsm_state6_blk = 1'b0;

always @ (*) begin
    if ((grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_done == 1'b0)) begin
        ap_ST_fsm_state7_blk = 1'b1;
    end else begin
        ap_ST_fsm_state7_blk = 1'b0;
    end
end

assign ap_ST_fsm_state8_blk = 1'b0;

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state8) | ((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b0)))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state8)) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state8)) begin
        messageBlocks_address0 = zext_ln226_fu_194_p1;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        messageBlocks_address0 = 64'd24;
    end else if ((1'b1 == ap_CS_fsm_state7)) begin
        messageBlocks_address0 = grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_address0;
    end else if ((1'b1 == ap_CS_fsm_state5)) begin
        messageBlocks_address0 = grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_address0;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        messageBlocks_address0 = grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_address0;
    end else begin
        messageBlocks_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state8) | (1'b1 == ap_CS_fsm_state3))) begin
        messageBlocks_ce0 = 1'b1;
    end else if ((1'b1 == ap_CS_fsm_state7)) begin
        messageBlocks_ce0 = grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_ce0;
    end else if ((1'b1 == ap_CS_fsm_state5)) begin
        messageBlocks_ce0 = grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_ce0;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        messageBlocks_ce0 = grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_ce0;
    end else begin
        messageBlocks_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state8)) begin
        messageBlocks_d0 = 5'd0;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        messageBlocks_d0 = 5'd17;
    end else if ((1'b1 == ap_CS_fsm_state7)) begin
        messageBlocks_d0 = grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_d0;
    end else if ((1'b1 == ap_CS_fsm_state5)) begin
        messageBlocks_d0 = grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_d0;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        messageBlocks_d0 = grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_d0;
    end else begin
        messageBlocks_d0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state8) | (1'b1 == ap_CS_fsm_state3))) begin
        messageBlocks_we0 = 1'b1;
    end else if ((1'b1 == ap_CS_fsm_state7)) begin
        messageBlocks_we0 = grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_messageBlocks_we0;
    end else if ((1'b1 == ap_CS_fsm_state5)) begin
        messageBlocks_we0 = grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_messageBlocks_we0;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        messageBlocks_we0 = grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_messageBlocks_we0;
    end else begin
        messageBlocks_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((1'b0 == ap_block_state2_on_subcall_done) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state5 : begin
            if (((grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state5))) begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end
        end
        ap_ST_fsm_state6 : begin
            ap_NS_fsm = ap_ST_fsm_state7;
        end
        ap_ST_fsm_state7 : begin
            if (((grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state7))) begin
                ap_NS_fsm = ap_ST_fsm_state8;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state7;
            end
        end
        ap_ST_fsm_state8 : begin
            ap_NS_fsm = ap_ST_fsm_state1;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln224_fu_173_p2 = (tmp_19_cast_fu_165_p3 + trunc_ln224_fu_157_p1);

assign add_ln226_fu_189_p2 = (add_ln224_reg_222 + 17'd512);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd5];

assign ap_CS_fsm_state7 = ap_CS_fsm[32'd6];

assign ap_CS_fsm_state8 = ap_CS_fsm[32'd7];

always @ (*) begin
    ap_block_state2_on_subcall_done = ((grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_done == 1'b0) | (grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_done == 1'b0));
end

assign ap_return = ($signed(sext_ln207_fu_180_p1) + $signed(25'd1));

assign grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_start = grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_ap_start_reg;

assign grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_start = grp_padv4_Pipeline_VITIS_LOOP_209_2_fu_83_ap_start_reg;

assign grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_start = grp_padv4_Pipeline_VITIS_LOOP_215_3_fu_91_ap_start_reg;

assign grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_start = grp_padv4_Pipeline_VITIS_LOOP_223_4_fu_97_ap_start_reg;

assign select_ln207_fu_149_p3 = ((p_cond_loc_fu_44[0:0] == 1'b1) ? sub_ln207_fu_129_p2 : zext_ln207_1_fu_145_p1);

assign sext_ln207_fu_180_p1 = select_ln207_reg_217;

assign sub_ln207_fu_129_p2 = (24'd0 - zext_ln207_fu_125_p1);

assign tmp_19_cast_fu_165_p3 = {{trunc_ln224_1_fu_161_p1}, {9'd0}};

assign trunc_ln207_1_fu_115_p4 = {{sub_ln203_loc_fu_40[31:9]}};

assign trunc_ln207_2_fu_135_p4 = {{grp_padv4_Pipeline_VITIS_LOOP_203_1_fu_76_sizeNeeded_out[31:9]}};

assign trunc_ln224_1_fu_161_p1 = select_ln207_fu_149_p3[7:0];

assign trunc_ln224_fu_157_p1 = select_ln207_fu_149_p3[16:0];

assign zext_ln207_1_fu_145_p1 = trunc_ln207_2_fu_135_p4;

assign zext_ln207_fu_125_p1 = trunc_ln207_1_fu_115_p4;

assign zext_ln226_fu_194_p1 = add_ln226_fu_189_p2;

endmodule //main_padv4
