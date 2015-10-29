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
            available <= 0;
        end
    end
endmodule
