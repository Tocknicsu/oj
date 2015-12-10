module controller;
reg clk, reset;
wire [7:0] led;


lab9 _lab9(clk, reset, led);

initial begin
    clk <= 0;
    reset <= 0;
    # 5
    reset <= 1;
    # 5 
    reset <= 0;
end
always #5 begin
    clk <= clk + 1;
end
initial #1000000 begin
    $finish;
end
endmodule
