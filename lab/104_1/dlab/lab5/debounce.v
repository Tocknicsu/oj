
module debounce(input  clk, input btn_input, output btn_output);

parameter DEBOUNCE_PERIOD = 1000000; /* 20 msec @ 50MHz */

reg [20:0] counter;
reg debounced_btn_state;
reg pressed;

assign btn_output = debounced_btn_state;

always@(posedge clk) begin
	if (btn_input == 0) begin
		counter <= 0;
		pressed <= 0;
	end else begin
		if (counter < DEBOUNCE_PERIOD) begin
			counter <= counter + 1;
		end else if(counter == DEBOUNCE_PERIOD) begin
			counter <= counter + 1;
			debounced_btn_state <= 1;
		end else if(counter > DEBOUNCE_PERIOD) begin
			debounced_btn_state <= 0;
		end
  end
end
endmodule
