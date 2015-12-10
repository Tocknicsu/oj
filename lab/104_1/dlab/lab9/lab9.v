module lab9(
    input clk,
    input reset,
    output [7:0] led
);

localparam [7:0] S_INIT = 0, S_INIT_PRE_WRITE = 1, S_INIT_WRIGING = 2, S_INIT_DONE = 3;
localparam [7:0] S_FIND_PRE_LOAD  = 4, S_FIND_LOADING = 5, S_FIND_LOAD_DONE = 6, S_FIND_DONE = 7, S_FIND_NEXT = 8;
localparam [7:0] S_ERASE_INIT = 9, S_ERASE_PRE_WRITE = 10, S_ERASE_WRITING = 11, S_ERASE_DONE = 12;
localparam [7:0] S_DONE = 100;
reg [7:0] P_STATUS, P_NEXT_STATUS;
reg [9:0] index_i, index_j, next_index_i, next_index_j;
reg [1023:0] sram;
reg look_i;
reg [15:0] primes[255:0];
wire [9:0] sram_addr;
reg data_in;
reg data_out;
reg write;
assign sram_addr = look_i ? index_i : index_j * index_i;
integer prime_counter;
integer show_counter, next_show_counter;
reg dir_plus;
assign led = primes[index_i];

always @(posedge clk) begin
    if (write) begin
        sram[sram_addr] <= data_in;
        data_out <= data_in;
    end else begin
        data_out <= sram[sram_addr];
    end
end

always @(*) begin
    case (P_STATUS)
        S_INIT: 
            begin
                P_NEXT_STATUS = S_INIT_PRE_WRITE;
                next_index_i = 0;
            end
        S_INIT_PRE_WRITE:
            P_NEXT_STATUS = S_INIT_WRIGING;
        S_INIT_WRIGING: 
            if(index_i == 1022) P_NEXT_STATUS = S_INIT_DONE;
            else begin
                P_NEXT_STATUS = S_INIT_PRE_WRITE;
                next_index_i = index_i + 1;
            end
        S_INIT_DONE: 
            begin
                P_NEXT_STATUS = S_FIND_PRE_LOAD;
                next_index_i = 0;
            end
        S_FIND_PRE_LOAD: 
            P_NEXT_STATUS = S_FIND_LOADING;
        S_FIND_LOADING: 
            P_NEXT_STATUS = S_FIND_LOAD_DONE;
        S_FIND_LOAD_DONE:
            if(data_out == 1)
                P_NEXT_STATUS = S_ERASE_INIT;
            else begin
                P_NEXT_STATUS = S_FIND_NEXT;
            end
        S_FIND_NEXT:
            if(index_i == 1022)
                P_NEXT_STATUS = S_FIND_DONE;
            else begin
                P_NEXT_STATUS = S_FIND_PRE_LOAD;
                next_index_i = index_i + 1;
            end
        S_FIND_DONE: 
            begin
                P_NEXT_STATUS = S_DONE;
                next_index_i = 0;
                next_index_j = 1;
            end
        S_ERASE_INIT: 
            if(index_i * 2 <= 1022) begin
                next_index_j = 2;
                P_NEXT_STATUS = S_ERASE_PRE_WRITE;
            end else begin
                P_NEXT_STATUS = S_FIND_NEXT;
            end
        S_ERASE_PRE_WRITE: 
            P_NEXT_STATUS = S_ERASE_WRITING;
        S_ERASE_WRITING: 
            P_NEXT_STATUS = S_ERASE_DONE;
        S_ERASE_DONE: 
            if(index_i * (index_j + 1) <= 1022) begin
                next_index_j <= index_j + 1;
                P_NEXT_STATUS = S_ERASE_PRE_WRITE;
            end else begin
                P_NEXT_STATUS = S_FIND_NEXT;
            end
        S_DONE:
            if(show_counter == 100) begin
                next_show_counter <= 0;
                if(dir_plus) begin
                    if(index_i == 171) next_index_i = 0;
                    else next_index_i = index_i + 1;
                    if(index_j == 171) next_index_j = 0;
                    else next_index_j = index_j + 1;
                end else begin
                    if(index_i == 0) next_index_i = 171;
                    else next_index_i = index_i - 1;
                    if(index_j == 0) next_index_j = 171;
                    else next_index_j = index_j - 1;
                end
            end else begin
                next_show_counter <= show_counter + 1;
            end
        default: begin
        end
    endcase

end

always @(posedge clk) begin
    if(reset) begin
        P_STATUS <= S_INIT;
        dir_plus <= 0;
        write <= 0;
        prime_counter <= 0;
        show_counter <= 0;
    end else begin
        if(P_STATUS == S_DONE) begin
            if(show_counter == 0)
                $display("counter: ", show_counter, " i:", index_i+1, " j:", index_j+1, " prime i:", primes[index_i], "prime j:", primes[index_j]);
            show_counter <= next_show_counter;
        end else if(P_STATUS == S_INIT) begin
        end else if(P_STATUS == S_INIT_PRE_WRITE) begin
            look_i <= 1;
            write <= 1;
            if(next_index_i == 0 || next_index_i == 1)
                data_in <= 0;
            else
                data_in <= 1;
        end else if(P_STATUS == S_INIT_WRIGING) begin
            write <= 0;
        end else if(P_STATUS == S_INIT_DONE) begin
        end else if(P_STATUS == S_FIND_PRE_LOAD) begin
            look_i <= 1;
        end else if(P_STATUS == S_FIND_LOADING) begin
        end else if(P_STATUS == S_FIND_LOAD_DONE) begin
            if(data_out) begin
                prime_counter <= prime_counter + 1;
                primes[prime_counter] <= index_i;
            end
        end else if(P_STATUS == S_FIND_NEXT) begin
        end else if(P_STATUS == S_ERASE_INIT) begin
        end else if(P_STATUS == S_ERASE_PRE_WRITE) begin
            look_i <= 0;
            write <= 1;
            data_in <= 0;
        end else if(P_STATUS == S_ERASE_WRITING) begin
            write <= 0;
        end
        index_i <= next_index_i;
        index_j <= next_index_j;
        P_STATUS <= P_NEXT_STATUS;
    end
end
endmodule
