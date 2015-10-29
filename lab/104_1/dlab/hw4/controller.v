module controller;
reg clk, rst;
wire [7:0] led;


data_template dd(clk, rst, led);

initial begin
    clk <= 0;
    rst <= 0;
    # 5
    rst <= 1;
    # 5 
    rst <= 0;
end
always #5 begin
    clk <= clk + 1;
end
initial #500 begin
    $display(led);
    $finish;
end
endmodule
