`timescale 1ns / 1ps
module data_template(input clk, input rst, output [31:0] sum);

wire data_available;
wire [7:0] in0, in1, in2, in3, in4, in5, in6, in7;
reg [7:0] data0[0:31];
reg [7:0] data1[0:31];
reg [7:0] data2[0:31];
reg [7:0] data3[0:31];
reg [7:0] data4[0:31];
reg [7:0] data5[0:31];
reg [7:0] data6[0:31];
reg [7:0] data7[0:31];
reg [5:0] count;
reg available;

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
    .sum(sum)
);
always @(posedge clk)
    if (rst) begin
        `include "data.dat"
        count <= 0;
        data_available <= 0;
    end else begin
        if( count < 32 ) begin
            available <= 1;
            count <= count + 1;
        end else begin
            available <= 0;
        end
    else;
endmodule

module mux(
);
endmodule
