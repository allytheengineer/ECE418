-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
-- Version: 2021.2
-- Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity main_padv4_Pipeline_VITIS_LOOP_215_3 is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    messageBlocks_address0 : OUT STD_LOGIC_VECTOR (16 downto 0);
    messageBlocks_ce0 : OUT STD_LOGIC;
    messageBlocks_we0 : OUT STD_LOGIC;
    messageBlocks_d0 : OUT STD_LOGIC_VECTOR (4 downto 0) );
end;


architecture behav of main_padv4_Pipeline_VITIS_LOOP_215_3 is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_pp0_stage0 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_boolean_0 : BOOLEAN := false;
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_18 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000011000";
    constant ap_const_lv5_10 : STD_LOGIC_VECTOR (4 downto 0) := "10000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv32_1F : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000011111";
    constant ap_const_lv8_0 : STD_LOGIC_VECTOR (7 downto 0) := "00000000";
    constant ap_const_lv9_1FF : STD_LOGIC_VECTOR (8 downto 0) := "111111111";
    constant ap_const_lv17_0 : STD_LOGIC_VECTOR (16 downto 0) := "00000000000000000";
    constant ap_const_lv10_1BF : STD_LOGIC_VECTOR (9 downto 0) := "0110111111";
    constant ap_const_lv16_1 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000000001";
    constant ap_const_lv32_9 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001001";
    constant ap_const_lv32_F : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001111";
    constant ap_const_lv7_1 : STD_LOGIC_VECTOR (6 downto 0) := "0000001";
    constant ap_const_lv9_0 : STD_LOGIC_VECTOR (8 downto 0) := "000000000";

attribute shreg_extract : string;
    signal ap_CS_fsm : STD_LOGIC_VECTOR (0 downto 0) := "1";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_pp0_stage0 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp0_stage0 : signal is "none";
    signal ap_enable_reg_pp0_iter0 : STD_LOGIC;
    signal ap_enable_reg_pp0_iter1 : STD_LOGIC := '0';
    signal ap_enable_reg_pp0_iter2 : STD_LOGIC := '0';
    signal ap_idle_pp0 : STD_LOGIC;
    signal ap_block_state1_pp0_stage0_iter0 : BOOLEAN;
    signal ap_block_state2_pp0_stage0_iter1 : BOOLEAN;
    signal ap_block_state3_pp0_stage0_iter2 : BOOLEAN;
    signal ap_block_pp0_stage0_subdone : BOOLEAN;
    signal icmp_ln215_fu_140_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_condition_exit_pp0_iter0_stage0 : STD_LOGIC;
    signal ap_loop_exit_ready : STD_LOGIC;
    signal ap_ready_int : STD_LOGIC;
    signal iter_1_fu_82_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal iter_1_reg_230 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_block_pp0_stage0_11001 : BOOLEAN;
    signal select_ln215_fu_128_p3 : STD_LOGIC_VECTOR (16 downto 0);
    signal select_ln215_reg_235 : STD_LOGIC_VECTOR (16 downto 0);
    signal select_ln216_fu_182_p3 : STD_LOGIC_VECTOR (6 downto 0);
    signal select_ln216_reg_244 : STD_LOGIC_VECTOR (6 downto 0);
    signal add_ln216_2_fu_210_p2 : STD_LOGIC_VECTOR (16 downto 0);
    signal add_ln216_2_reg_250 : STD_LOGIC_VECTOR (16 downto 0);
    signal zext_ln216_2_fu_219_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_block_pp0_stage0 : BOOLEAN;
    signal iter_fu_52 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_sig_allocacmp_iter_load : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_loop_init : STD_LOGIC;
    signal trunc_ln215_fu_96_p1 : STD_LOGIC_VECTOR (8 downto 0);
    signal empty_fu_78_p1 : STD_LOGIC_VECTOR (8 downto 0);
    signal xor_ln215_fu_108_p2 : STD_LOGIC_VECTOR (8 downto 0);
    signal p_and_t3_cast_fu_114_p3 : STD_LOGIC_VECTOR (16 downto 0);
    signal tmp_fu_88_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal sub_ln215_fu_122_p2 : STD_LOGIC_VECTOR (16 downto 0);
    signal p_and_f_cast_fu_100_p3 : STD_LOGIC_VECTOR (16 downto 0);
    signal trunc_ln215_1_fu_136_p1 : STD_LOGIC_VECTOR (9 downto 0);
    signal empty_37_fu_146_p1 : STD_LOGIC_VECTOR (15 downto 0);
    signal trunc_ln216_1_fu_156_p4 : STD_LOGIC_VECTOR (6 downto 0);
    signal add_ln208_1_fu_150_p2 : STD_LOGIC_VECTOR (15 downto 0);
    signal add_ln216_fu_166_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal trunc_ln216_2_fu_172_p4 : STD_LOGIC_VECTOR (6 downto 0);
    signal tmp_s_fu_193_p3 : STD_LOGIC_VECTOR (15 downto 0);
    signal zext_ln216_1_fu_200_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal zext_ln216_fu_190_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal add_ln216_1_fu_204_p2 : STD_LOGIC_VECTOR (16 downto 0);
    signal ap_done_reg : STD_LOGIC := '0';
    signal ap_continue_int : STD_LOGIC;
    signal ap_done_int : STD_LOGIC;
    signal ap_loop_exit_ready_pp0_iter1_reg : STD_LOGIC;
    signal ap_NS_fsm : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_enable_pp0 : STD_LOGIC;
    signal ap_start_int : STD_LOGIC;
    signal ap_ce_reg : STD_LOGIC;

    component main_flow_control_loop_pipe_sequential_init IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_start_int : OUT STD_LOGIC;
        ap_loop_init : OUT STD_LOGIC;
        ap_ready_int : IN STD_LOGIC;
        ap_loop_exit_ready : IN STD_LOGIC;
        ap_loop_exit_done : IN STD_LOGIC;
        ap_continue_int : OUT STD_LOGIC;
        ap_done_int : IN STD_LOGIC );
    end component;



begin
    flow_control_loop_pipe_sequential_init_U : component main_flow_control_loop_pipe_sequential_init
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => ap_start,
        ap_ready => ap_ready,
        ap_done => ap_done,
        ap_start_int => ap_start_int,
        ap_loop_init => ap_loop_init,
        ap_ready_int => ap_ready_int,
        ap_loop_exit_ready => ap_condition_exit_pp0_iter0_stage0,
        ap_loop_exit_done => ap_done_int,
        ap_continue_int => ap_continue_int,
        ap_done_int => ap_done_int);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_pp0_stage0;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    ap_done_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_done_reg <= ap_const_logic_0;
            else
                if ((ap_continue_int = ap_const_logic_1)) then 
                    ap_done_reg <= ap_const_logic_0;
                elsif (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_exit_ready_pp0_iter1_reg = ap_const_logic_1))) then 
                    ap_done_reg <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter1_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter1 <= ap_const_logic_0;
            else
                if ((ap_const_logic_1 = ap_condition_exit_pp0_iter0_stage0)) then 
                    ap_enable_reg_pp0_iter1 <= ap_const_logic_0;
                elsif (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
                    ap_enable_reg_pp0_iter1 <= ap_start_int;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter2_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter2 <= ap_const_logic_0;
            else
                if ((ap_const_boolean_0 = ap_block_pp0_stage0_subdone)) then 
                    ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
                end if; 
            end if;
        end if;
    end process;


    iter_fu_52_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                if ((ap_loop_init = ap_const_logic_1)) then 
                    iter_fu_52 <= ap_const_lv32_18;
                elsif ((ap_enable_reg_pp0_iter1 = ap_const_logic_1)) then 
                    iter_fu_52 <= iter_1_reg_230;
                end if;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                add_ln216_2_reg_250 <= add_ln216_2_fu_210_p2;
                ap_loop_exit_ready_pp0_iter1_reg <= ap_loop_exit_ready;
                iter_1_reg_230 <= iter_1_fu_82_p2;
                select_ln215_reg_235 <= select_ln215_fu_128_p3;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln215_fu_140_p2 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                select_ln216_reg_244 <= select_ln216_fu_182_p3;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_CS_fsm)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_pp0_stage0 => 
                ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
            when others =>  
                ap_NS_fsm <= "X";
        end case;
    end process;
    add_ln208_1_fu_150_p2 <= std_logic_vector(unsigned(empty_37_fu_146_p1) + unsigned(ap_const_lv16_1));
    add_ln216_1_fu_204_p2 <= std_logic_vector(unsigned(zext_ln216_1_fu_200_p1) + unsigned(zext_ln216_fu_190_p1));
    add_ln216_2_fu_210_p2 <= std_logic_vector(unsigned(add_ln216_1_fu_204_p2) + unsigned(select_ln215_reg_235));
    add_ln216_fu_166_p2 <= std_logic_vector(unsigned(trunc_ln216_1_fu_156_p4) + unsigned(ap_const_lv7_1));
    ap_CS_fsm_pp0_stage0 <= ap_CS_fsm(0);
        ap_block_pp0_stage0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_11001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_subdone <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state1_pp0_stage0_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state2_pp0_stage0_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state3_pp0_stage0_iter2 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_condition_exit_pp0_iter0_stage0_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0, ap_block_pp0_stage0_subdone, icmp_ln215_fu_140_p2)
    begin
        if (((icmp_ln215_fu_140_p2 = ap_const_lv1_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            ap_condition_exit_pp0_iter0_stage0 <= ap_const_logic_1;
        else 
            ap_condition_exit_pp0_iter0_stage0 <= ap_const_logic_0;
        end if; 
    end process;


    ap_done_int_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_subdone, ap_done_reg, ap_loop_exit_ready_pp0_iter1_reg)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_exit_ready_pp0_iter1_reg = ap_const_logic_1))) then 
            ap_done_int <= ap_const_logic_1;
        else 
            ap_done_int <= ap_done_reg;
        end if; 
    end process;

    ap_enable_pp0 <= (ap_idle_pp0 xor ap_const_logic_1);
    ap_enable_reg_pp0_iter0 <= ap_start_int;

    ap_idle_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_idle_pp0, ap_start_int)
    begin
        if (((ap_idle_pp0 = ap_const_logic_1) and (ap_start_int = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_pp0_assign_proc : process(ap_enable_reg_pp0_iter0, ap_enable_reg_pp0_iter1, ap_enable_reg_pp0_iter2)
    begin
        if (((ap_enable_reg_pp0_iter2 = ap_const_logic_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_0))) then 
            ap_idle_pp0 <= ap_const_logic_1;
        else 
            ap_idle_pp0 <= ap_const_logic_0;
        end if; 
    end process;

    ap_loop_exit_ready <= ap_condition_exit_pp0_iter0_stage0;

    ap_ready_int_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0, ap_block_pp0_stage0_subdone)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            ap_ready_int <= ap_const_logic_1;
        else 
            ap_ready_int <= ap_const_logic_0;
        end if; 
    end process;


    ap_sig_allocacmp_iter_load_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter1, iter_1_reg_230, ap_block_pp0_stage0, iter_fu_52, ap_loop_init)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
            if ((ap_loop_init = ap_const_logic_1)) then 
                ap_sig_allocacmp_iter_load <= ap_const_lv32_18;
            elsif ((ap_enable_reg_pp0_iter1 = ap_const_logic_1)) then 
                ap_sig_allocacmp_iter_load <= iter_1_reg_230;
            else 
                ap_sig_allocacmp_iter_load <= iter_fu_52;
            end if;
        else 
            ap_sig_allocacmp_iter_load <= iter_fu_52;
        end if; 
    end process;

    empty_37_fu_146_p1 <= ap_sig_allocacmp_iter_load(16 - 1 downto 0);
    empty_fu_78_p1 <= ap_sig_allocacmp_iter_load(9 - 1 downto 0);
    icmp_ln215_fu_140_p2 <= "1" when (trunc_ln215_1_fu_136_p1 = ap_const_lv10_1BF) else "0";
    iter_1_fu_82_p2 <= std_logic_vector(unsigned(ap_sig_allocacmp_iter_load) + unsigned(ap_const_lv32_1));
    messageBlocks_address0 <= zext_ln216_2_fu_219_p1(17 - 1 downto 0);

    messageBlocks_ce0_assign_proc : process(ap_enable_reg_pp0_iter2, ap_block_pp0_stage0_11001)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1))) then 
            messageBlocks_ce0 <= ap_const_logic_1;
        else 
            messageBlocks_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    messageBlocks_d0 <= ap_const_lv5_10;

    messageBlocks_we0_assign_proc : process(ap_enable_reg_pp0_iter2, ap_block_pp0_stage0_11001)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1))) then 
            messageBlocks_we0 <= ap_const_logic_1;
        else 
            messageBlocks_we0 <= ap_const_logic_0;
        end if; 
    end process;

    p_and_f_cast_fu_100_p3 <= (ap_const_lv8_0 & trunc_ln215_fu_96_p1);
    p_and_t3_cast_fu_114_p3 <= (ap_const_lv8_0 & xor_ln215_fu_108_p2);
    select_ln215_fu_128_p3 <= 
        sub_ln215_fu_122_p2 when (tmp_fu_88_p3(0) = '1') else 
        p_and_f_cast_fu_100_p3;
    select_ln216_fu_182_p3 <= 
        add_ln216_fu_166_p2 when (tmp_fu_88_p3(0) = '1') else 
        trunc_ln216_2_fu_172_p4;
    sub_ln215_fu_122_p2 <= std_logic_vector(unsigned(ap_const_lv17_0) - unsigned(p_and_t3_cast_fu_114_p3));
    tmp_fu_88_p3 <= iter_1_fu_82_p2(31 downto 31);
    tmp_s_fu_193_p3 <= (select_ln216_reg_244 & ap_const_lv9_0);
    trunc_ln215_1_fu_136_p1 <= select_ln215_fu_128_p3(10 - 1 downto 0);
    trunc_ln215_fu_96_p1 <= iter_1_fu_82_p2(9 - 1 downto 0);
    trunc_ln216_1_fu_156_p4 <= ap_sig_allocacmp_iter_load(15 downto 9);
    trunc_ln216_2_fu_172_p4 <= add_ln208_1_fu_150_p2(15 downto 9);
    xor_ln215_fu_108_p2 <= (empty_fu_78_p1 xor ap_const_lv9_1FF);
    zext_ln216_1_fu_200_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_s_fu_193_p3),17));
    zext_ln216_2_fu_219_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln216_2_reg_250),64));
    zext_ln216_fu_190_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(select_ln216_reg_244),17));
end behav;
