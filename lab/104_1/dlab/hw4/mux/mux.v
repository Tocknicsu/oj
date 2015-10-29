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
