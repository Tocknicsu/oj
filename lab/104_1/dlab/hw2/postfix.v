module postfix (
    input wire [3:0]IN,
    input wire CLK, 
    input wire RESET,
    input wire IN_VALID, 
    input wire OP_MODE, 
    output wire [15:0]OUT, 
    output wire OUT_VALID
);

reg [15:0] stack [20:0], REG_OUT_VALID;
reg [15:0] REG_OUT;
integer index, empty;
assign OUT_VALID=REG_OUT_VALID;
assign OUT=REG_OUT;

always @(negedge RESET)
begin
    index = 0;
    empty = 0;
    REG_OUT_VALID = 0;
end


always @(posedge CLK)
begin
	if(REG_OUT_VALID)
		begin
			REG_OUT_VALID = 0;
			REG_OUT = 0;
		end
	if(IN_VALID)
		begin
			if(OP_MODE)
				begin
					case (IN)
						4'b0001: stack[index-2] = stack[index-2] + stack[index-1];
						4'b0010: stack[index-2] = stack[index-2] - stack[index-1];
						4'b0100: stack[index-2] = stack[index-2] * stack[index-1];
						default: ;
					endcase
					index = index - 1;
				end
			else
				begin
					stack[index] <= IN;
					index = index + 1;
				end
		end
	else
		begin				
			if(index != 0)
				begin
					REG_OUT_VALID = 1;
					REG_OUT = stack[0];
					index = 0;
					empty = 0;
				end
		end
end
endmodule
