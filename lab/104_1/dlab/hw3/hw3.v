`timescale 1ns / 1ps

module lab3(
    input  clk,
    input  reset,
    input  btn_east,
    input  btn_west,
    output [7:0] led
);

integer east_count, west_count, east_down, west_down;
reg signed [7:0] value;
assign led=value;


always @(posedge clk)
begin
    if(reset) begin
        value <= 0;
        east_count <= 0;
        east_down <= 0;
        west_count <= 0;
        west_down <= 0;
    end else begin
        if(btn_east)
            east_count <= east_count + 1;
        else begin
            east_count <= 0;
            east_down <= 0;
        end

        if(btn_west)
            west_count <= west_count + 1;
        else begin
            west_count <= 0;
            west_down <= 0;
        end

        if(west_count == 123456 & value < 7 & !west_down) begin
            value <= value + 1;
            west_down <= 1;
        end else begin
		  end
        if(east_count == 123456 & value > -8 & !east_down) begin
            value <= value - 1;
            east_down <= 1;
        end else begin
		  end
    end
end
endmodule

