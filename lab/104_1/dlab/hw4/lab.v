`timescale 1ns / 1ps
module data_template(input clk, input rst, output [7:0] sum);

wire [7:0] in0, in1, in2, in3, in4, in5, in6, in7;
reg [7:0] data0[0:31];
reg [7:0] data1[0:31];
reg [7:0] data2[0:31];
reg [7:0] data3[0:31];
reg [7:0] data4[0:31];
reg [7:0] data5[0:31];
reg [7:0] data6[0:31];
reg [7:0] data7[0:31];
wire [31:0] tmp_sum;
integer count;
reg available;
wire data_available;

assign data_available = available;
assign in0 = data0[0];
assign in1 = data1[0];
assign in2 = data2[0];
assign in3 = data3[0];
assign in4 = data4[0];
assign in5 = data5[0];
assign in6 = data6[0];
assign in7 = data7[0];
assign sum = (tmp_sum + 128) / 256;
integer i;

adder_tree add (
    .clk(clk),
    .rst(rst),
    .in_valid(data_available),
    .in0(in0),
    .in1(in1),
    .in2(in2),
    .in3(in3),
    .in4(in4),
    .in5(in5),
    .in6(in6),
    .in7(in7),
    .sum(tmp_sum)
);

always @(posedge clk)
    if (rst) begin
        `include "data.dat"
        available <= 0;
        count <= 0;
    end else begin
        if( count < 32 ) begin
            available <= 1;
            for(i = 0 ; i < 32 ; i = i + 1) begin
                data0[i] <= data0[(i+1)%32];
                data1[i] <= data1[(i+1)%32];
                data2[i] <= data2[(i+1)%32];
                data3[i] <= data3[(i+1)%32];
                data4[i] <= data4[(i+1)%32];
                data5[i] <= data5[(i+1)%32];
                data6[i] <= data6[(i+1)%32];
                data7[i] <= data7[(i+1)%32];
            end
            count <= count + 1;
        end else begin
            $display(tmp_sum);
            available <= 0;
        end
    end
endmodule
/*
module mux(
	input [7:0] in0,
	input [7:0] in1,
	input [7:0] in2,
	input [7:0] in3,
	input [7:0] in4,
	input [7:0] in5,
	input [7:0] in6,
	input [7:0] in7,
	input [7:0] in8,
	input [7:0] in9,
	input [7:0] in10,
	input [7:0] in11,
	input [7:0] in12,
	input [7:0] in13,
	input [7:0] in14,
	input [7:0] in15,
	input [7:0] in16,
	input [7:0] in17,
	input [7:0] in18,
	input [7:0] in19,
	input [7:0] in20,
	input [7:0] in21,
	input [7:0] in22,
	input [7:0] in23,
	input [7:0] in24,
	input [7:0] in25,
	input [7:0] in26,
	input [7:0] in27,
	input [7:0] in28,
	input [7:0] in29,
	input [7:0] in30,
	input [7:0] in31,
	input [4:0] cnt,
	output [7:0] out
);
reg [7:0] value;
assign out=value;
always @(*) begin
	case (cnt)
		0: value<=in0;
		1: value<=in1;
		2: value<=in2;
		3: value<=in3;
		4: value<=in4;
		5: value<=in5;
		6: value<=in6;
		7: value<=in7;
		8: value<=in8;
		9: value<=in9;
		10: value<=in10;
		11: value<=in11;
		12: value<=in12;
		13: value<=in13;
		14: value<=in14;
		15: value<=in15;
		16: value<=in16;
		17: value<=in17;
		18: value<=in18;
		19: value<=in19;
		20: value<=in20;
		21: value<=in21;
		22: value<=in22;
		23: value<=in23;
		24: value<=in24;
		25: value<=in25;
		26: value<=in26;
		27: value<=in27;
		28: value<=in28;
		29: value<=in29;
		30: value<=in30;
		31: value<=in31;
	endcase
end
endmodule

`timescale 1ns / 1ps
module template(input clk, input rst, output [7:0] sum);

wire [31:0] tmp_sum;
wire [7:0] in0, in1, in2, in3, in4, in5, in6, in7;
wire [7:0] next_in0, next_in1, next_in2, next_in3, next_in4, next_in5, next_in6, next_in7;
reg [7:0] reg_in0, reg_in1, reg_in2, reg_in3, reg_in4, reg_in5, reg_in6, reg_in7;
reg [7:0] data0[0:31];
reg [7:0] data1[0:31];
reg [7:0] data2[0:31];
reg [7:0] data3[0:31];
reg [7:0] data4[0:31];
reg [7:0] data5[0:31];
reg [7:0] data6[0:31];
reg [7:0] data7[0:31];
reg [7:0] cnt;
reg available;
assign sum = (tmp_sum + 128) / 256;
assign data_available=available;
integer i;

assign in0=reg_in0;
mux mux_0(.in0(data0[0]),.in1(data0[1]),.in2(data0[2]),.in3(data0[3]),.in4(data0[4]),.in5(data0[5]),.in6(data0[6]),.in7(data0[7]),.in8(data0[8]),.in9(data0[9]),.in10(data0[10]),.in11(data0[11]),.in12(data0[12]),.in13(data0[13]),.in14(data0[14]),.in15(data0[15]),.in16(data0[16]),.in17(data0[17]),.in18(data0[18]),.in19(data0[19]),.in20(data0[20]),.in21(data0[21]),.in22(data0[22]),.in23(data0[23]),.in24(data0[24]),.in25(data0[25]),.in26(data0[26]),.in27(data0[27]),.in28(data0[28]),.in29(data0[29]),.in30(data0[30]),.in31(data0[31]),.cnt(cnt), .out(next_in0));
assign in1=reg_in1;
mux mux_1(.in0(data1[0]),.in1(data1[1]),.in2(data1[2]),.in3(data1[3]),.in4(data1[4]),.in5(data1[5]),.in6(data1[6]),.in7(data1[7]),.in8(data1[8]),.in9(data1[9]),.in10(data1[10]),.in11(data1[11]),.in12(data1[12]),.in13(data1[13]),.in14(data1[14]),.in15(data1[15]),.in16(data1[16]),.in17(data1[17]),.in18(data1[18]),.in19(data1[19]),.in20(data1[20]),.in21(data1[21]),.in22(data1[22]),.in23(data1[23]),.in24(data1[24]),.in25(data1[25]),.in26(data1[26]),.in27(data1[27]),.in28(data1[28]),.in29(data1[29]),.in30(data1[30]),.in31(data1[31]),.cnt(cnt), .out(next_in1));
assign in2=reg_in2;
mux mux_2(.in0(data2[0]),.in1(data2[1]),.in2(data2[2]),.in3(data2[3]),.in4(data2[4]),.in5(data2[5]),.in6(data2[6]),.in7(data2[7]),.in8(data2[8]),.in9(data2[9]),.in10(data2[10]),.in11(data2[11]),.in12(data2[12]),.in13(data2[13]),.in14(data2[14]),.in15(data2[15]),.in16(data2[16]),.in17(data2[17]),.in18(data2[18]),.in19(data2[19]),.in20(data2[20]),.in21(data2[21]),.in22(data2[22]),.in23(data2[23]),.in24(data2[24]),.in25(data2[25]),.in26(data2[26]),.in27(data2[27]),.in28(data2[28]),.in29(data2[29]),.in30(data2[30]),.in31(data2[31]),.cnt(cnt), .out(next_in2));
assign in3=reg_in3;
mux mux_3(.in0(data3[0]),.in1(data3[1]),.in2(data3[2]),.in3(data3[3]),.in4(data3[4]),.in5(data3[5]),.in6(data3[6]),.in7(data3[7]),.in8(data3[8]),.in9(data3[9]),.in10(data3[10]),.in11(data3[11]),.in12(data3[12]),.in13(data3[13]),.in14(data3[14]),.in15(data3[15]),.in16(data3[16]),.in17(data3[17]),.in18(data3[18]),.in19(data3[19]),.in20(data3[20]),.in21(data3[21]),.in22(data3[22]),.in23(data3[23]),.in24(data3[24]),.in25(data3[25]),.in26(data3[26]),.in27(data3[27]),.in28(data3[28]),.in29(data3[29]),.in30(data3[30]),.in31(data3[31]),.cnt(cnt), .out(next_in3));
assign in4=reg_in4;
mux mux_4(.in0(data4[0]),.in1(data4[1]),.in2(data4[2]),.in3(data4[3]),.in4(data4[4]),.in5(data4[5]),.in6(data4[6]),.in7(data4[7]),.in8(data4[8]),.in9(data4[9]),.in10(data4[10]),.in11(data4[11]),.in12(data4[12]),.in13(data4[13]),.in14(data4[14]),.in15(data4[15]),.in16(data4[16]),.in17(data4[17]),.in18(data4[18]),.in19(data4[19]),.in20(data4[20]),.in21(data4[21]),.in22(data4[22]),.in23(data4[23]),.in24(data4[24]),.in25(data4[25]),.in26(data4[26]),.in27(data4[27]),.in28(data4[28]),.in29(data4[29]),.in30(data4[30]),.in31(data4[31]),.cnt(cnt), .out(next_in4));
assign in5=reg_in5;
mux mux_5(.in0(data5[0]),.in1(data5[1]),.in2(data5[2]),.in3(data5[3]),.in4(data5[4]),.in5(data5[5]),.in6(data5[6]),.in7(data5[7]),.in8(data5[8]),.in9(data5[9]),.in10(data5[10]),.in11(data5[11]),.in12(data5[12]),.in13(data5[13]),.in14(data5[14]),.in15(data5[15]),.in16(data5[16]),.in17(data5[17]),.in18(data5[18]),.in19(data5[19]),.in20(data5[20]),.in21(data5[21]),.in22(data5[22]),.in23(data5[23]),.in24(data5[24]),.in25(data5[25]),.in26(data5[26]),.in27(data5[27]),.in28(data5[28]),.in29(data5[29]),.in30(data5[30]),.in31(data5[31]),.cnt(cnt), .out(next_in5));
assign in6=reg_in6;
mux mux_6(.in0(data6[0]),.in1(data6[1]),.in2(data6[2]),.in3(data6[3]),.in4(data6[4]),.in5(data6[5]),.in6(data6[6]),.in7(data6[7]),.in8(data6[8]),.in9(data6[9]),.in10(data6[10]),.in11(data6[11]),.in12(data6[12]),.in13(data6[13]),.in14(data6[14]),.in15(data6[15]),.in16(data6[16]),.in17(data6[17]),.in18(data6[18]),.in19(data6[19]),.in20(data6[20]),.in21(data6[21]),.in22(data6[22]),.in23(data6[23]),.in24(data6[24]),.in25(data6[25]),.in26(data6[26]),.in27(data6[27]),.in28(data6[28]),.in29(data6[29]),.in30(data6[30]),.in31(data6[31]),.cnt(cnt), .out(next_in6));
assign in7=reg_in7;
mux mux_7(.in0(data7[0]),.in1(data7[1]),.in2(data7[2]),.in3(data7[3]),.in4(data7[4]),.in5(data7[5]),.in6(data7[6]),.in7(data7[7]),.in8(data7[8]),.in9(data7[9]),.in10(data7[10]),.in11(data7[11]),.in12(data7[12]),.in13(data7[13]),.in14(data7[14]),.in15(data7[15]),.in16(data7[16]),.in17(data7[17]),.in18(data7[18]),.in19(data7[19]),.in20(data7[20]),.in21(data7[21]),.in22(data7[22]),.in23(data7[23]),.in24(data7[24]),.in25(data7[25]),.in26(data7[26]),.in27(data7[27]),.in28(data7[28]),.in29(data7[29]),.in30(data7[30]),.in31(data7[31]),.cnt(cnt), .out(next_in7));

adder_tree add (
    .clk(clk),
    .rst(rst),
    .in_valid(data_available),
    .in0(in0),
    .in1(in1),
    .in2(in2),
    .in3(in3),
    .in4(in4),
    .in5(in5),
    .in6(in6),
    .in7(in7),
    .sum(tmp_sum)
);
always @(posedge clk) begin
    if (rst) begin
        `include "data.dat"
        available <= 0;
        cnt <= 0;
    end else begin
        if( cnt < 32 ) begin

			reg_in0 <= next_in0;
			reg_in1 <= next_in1;
			reg_in2 <= next_in2;
			reg_in3 <= next_in3;
			reg_in4 <= next_in4;
			reg_in5 <= next_in5;
			reg_in6 <= next_in6;
			reg_in7 <= next_in7;

            available <= 1;
            cnt <= cnt + 1;
        end else begin
            available <= 0;
        end
    end

end
endmodule
*/
