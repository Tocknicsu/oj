module lab3(
    input wire CLK,
    input wire reset,
    input wire btn_east,
    input wire btn_west,
    output wire [7:0] led
);

integer east_count, west_count;
reg [7:0] value;
assign led=value;

always @(posedge CLK)
begin
    if(reset)
        value <= 0
    if(btn_east)
        east_count <= east_count + 1
    else
        east_count <= 0
    if(west_count)
        west_count <= west_count + 1
    else
        west_count <= 0
    if(west_count == 23456 & value < 7)
        value <= value + 1
    if(east_count == 23456 & value > -8)
        value <= value - 1
end

