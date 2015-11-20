`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:43:16 10/20/2015 
// Design Name: 
// Module Name:    lab5 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module lab5(
    input clk,
    input reset,
    input button,
    input rx,
    output tx,
    output [7:0] led
    );

localparam [1:0] S_IDLE = 2'b00, S_WAIT = 2'b01, S_SEND = 2'b10, S_INCR = 2'b11;
localparam MEM_SIZE = 256;

// declare system variables
wire btn_pressed;
reg [7:0] send_counter;
reg [1:0] Q, Q_next;
reg [7:0] data[0:MEM_SIZE-1];
integer idx;
integer count;

// declare UART signals
wire transmit;
wire received;
wire [7:0] rx_byte;
reg  [7:0] rx_temp;
wire [7:0] tx_byte;
wire is_receiving;
wire is_transmitting;
wire recv_error;

assign led = count;
assign tx_byte = data[send_counter];

debounce btn_db(
    .clk(clk),
    .btn_input(button),
    .btn_output(btn_pressed)
    );

uart uart(
    .clk(clk),
    .rst(reset),
    .rx(rx),
    .tx(tx),
    .transmit(transmit),
    .tx_byte(tx_byte),
    .received(received),
    .rx_byte(rx_byte),
    .is_receiving(is_receiving),
    .is_transmitting(is_transmitting),
    .recv_error(recv_error)
    );


// ------------------------------------------------------------------------
// FSM of the "Hello, World!" transmission controller

always @(posedge clk) begin
  if (reset) Q <= S_IDLE;
  else Q <= Q_next;
end

always @(*) begin // FSM next-state logic
  case (Q)
    S_IDLE: // wait for button click
      if (btn_pressed == 1) Q_next = S_WAIT;
      else Q_next = S_IDLE;
    S_WAIT: // wait for the transmission of current data byte begins
      if (is_transmitting == 1) Q_next = S_SEND;
      else Q_next = S_WAIT;
    S_SEND: // wait for the transmission of current data byte finishes
      if (is_transmitting == 0) Q_next = S_INCR; // transmit next character
      else Q_next = S_SEND;
    S_INCR:
      if (tx_byte == 8'h0) Q_next = S_IDLE; // string transmission ends
      else Q_next = S_WAIT;
  endcase
end

// FSM output logics
assign transmit = (Q == S_WAIT)? 1 : 0;

// FSM-controlled send_counter incrementing data path
always @(posedge clk) begin
  if (reset || (Q == S_IDLE))
    send_counter <= 0;
  else if (Q == S_INCR)
    send_counter <= send_counter + 1;
end

// End of the FSM of the "Hello, World! " transmission controller
// ------------------------------------------------------------------------

// ------------------------------------------------------------------------
// The following logic stores the UART input in a temporary buffer
// You must replace this code by your own code to store multiple
// bytes of data.
//
always @(posedge clk) begin
	if (reset) begin
		count <= 0;
		for(idx = 0 ; idx < MEM_SIZE ; idx = idx + 1)
			data[idx] <= 0;
	end else if (received) begin
		if(97 <= rx_byte && rx_byte <= 122)
			data[count] <= rx_byte-32;
		else
			data[count] <= rx_byte;
		count<= count + 1;
	end
end
// ------------------------------------------------------------------------

endmodule
