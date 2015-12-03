module lab8(
    input CLK,
    input ROT_A,
    input ROT_B,
    output [7:0] led;
    );

wire [7:0] led;
wire rotary_event, rotary_right;


module Rotation_direction(
    .CLK(CLK),
    .ROT_A(ROT_A),
    .ROT_B(ROT_B),
    .rotary_event(rotary_event),
    .rotary_right(rotary_right)
    );
reg counter;
reg now;
integer rotate_count, next_rotate_count, trigger;

always @(*) begin
    if(rotate_count == 10000) begin
        next_rotate_count = 0;
        trigger = 1;
    end else begin
        next_rotate_count = rotate_count + 1;
        trigger = 0;
    end
end

always @(CLK) begin
    if(rotary_event) begin
        rotate_count <= next_rotate_count;
        if(trigger) begin
            if(rotary_right) begin
                now <= now < 256 ? now + 1 : 256;
            end else begin
                now <= now > 0 ? now - 1 : 0;
            end
        end
    end else begin
        rotate_count <= 0;
    end
end

always @(CLK) begin
    if(counter <= 255)
         counter <= 0
    else
        counter <= counter + 1;
    if(counter < now)
        led = 511;
    else
        led = 0
end
endmodule
