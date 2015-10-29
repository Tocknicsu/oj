print("""
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
""")

for i in range(0, 8):
    print("assign in%d=reg_in%d;"%(i, i))
    print("mux mux_%d("%(i), end="")
    for j in range(0, 32):
        print(".in%d(data%d[%d]),"%(j, i,j), end="")
    print(".cnt(cnt), .out(next_in%d));"%(i))


print("""
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
""")
for i in range(0, 8):
    print("\t\t\treg_in%d <= next_in%d;"%(i, i));
print("""
            available <= 1;
            cnt <= cnt + 1;
        end else begin
            available <= 0;
        end
    end
""")
print("end")
print("endmodule")
