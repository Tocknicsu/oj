`timescale 1ns / 1ps

module postfix_tb;
  // Inputs
  reg         CLK, RESET, IN_VALID, OP_MODE;
  reg  [3:0]  IN;
  // Outputs
  wire        OUT_VALID;
  wire [15:0] OUT;
  reg  [15:0] YOUR_ANSWER;
  integer          i, j, error;
  integer          flag;
  parameter        CYCLE        = 10;
  always #(CYCLE/2.0) CLK = ~CLK;
  // Instantiate the Unit Under Test (UUT)
  postfix uut (
	 .CLK(CLK),
     .RESET(RESET),
     .IN_VALID(IN_VALID),
     .OP_MODE(OP_MODE),
     .IN(IN),
     .OUT_VALID(OUT_VALID),
     .OUT(OUT)
  );
initial 
begin  
  //initial
  CLK      = 0;         
  RESET    = 1;
  IN_VALID = 0; 
  OP_MODE  = 0;
  IN       = 'bx;    
  i        = 0;
  j        = 0;
  error    = 0;
  flag     = 0;
  //reset
  #(2*CYCLE);     
  @(posedge CLK);
  RESET = 0;
  @(posedge CLK);
  RESET = 1;
  #(1*CYCLE);
  @(posedge CLK);

  IN_VALID = 0; 

  IN       = 0; 

  OP_MODE  = 0;  

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd12; 

  OP_MODE  = 0; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd9; 

  OP_MODE  = 0; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd6; 

  OP_MODE  = 0; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'b0100; 

  OP_MODE  = 1'd1; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'b0001; 

  OP_MODE  = 1'd1; 

  

  @(posedge CLK);

  IN_VALID = 0; 

  IN       = 0; 

  OP_MODE  = 0;  

  

  @(posedge CLK);

  @(posedge CLK);

  

  

  @(posedge CLK);

  @(posedge CLK);

  @(posedge CLK);

  @(posedge CLK);

  

  if(flag)begin

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd15; 

  OP_MODE  = 0; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd8; 

  OP_MODE  = 0; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'b0100; 

  OP_MODE  = 1; 

  end

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd11; 

  OP_MODE  = 0; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'b0001; 

  OP_MODE  = 1; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd7; 

  OP_MODE  = 0; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd4; 

  OP_MODE  = 0; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'b0100; 

  OP_MODE  = 1; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'b0010; 

  OP_MODE  = 1; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd13; 

  OP_MODE  = 0; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd12; 

  OP_MODE  = 0; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd11; 

  OP_MODE  = 0; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'b0100; 

  OP_MODE  = 1; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'b0100; 

  OP_MODE  = 1; 

  

  @(posedge CLK);

  IN_VALID = 1'd1; 

  IN       = 4'd0001; 

  OP_MODE  = 1; 

  

  @(posedge CLK);

  IN_VALID = 0; 

  IN       = 0; 

  OP_MODE  = 0;  

  

  @(posedge CLK);

  @(posedge CLK);

end



//---------------------------------------------------------------------

// CHECK CORRECT PATTERN WITH DESIGN OUTPUT PATTERN           

//---------------------------------------------------------------------

always@(posedge CLK)

begin



  if(OUT_VALID && (i == 0))

  begin

    i = i+1;

    YOUR_ANSWER    = OUT[15:0];

    if(YOUR_ANSWER == 16'd66) ;

	else error = error+1;



    @(posedge CLK);

    @(posedge CLK);

    flag = 1;

    

  end

  

  if(OUT_VALID && flag)

  begin

    YOUR_ANSWER    = OUT[15:0];

    if(YOUR_ANSWER == 16'd1819);

    else error = error+1;

    @(posedge CLK);

    @(posedge CLK);

    i = i+1;

  end



  if(i == 2)begin

    if(error==0)begin

      $display ("--------------------------------------------------------------------");

      $display ("                             PASS!!!                                ");

      $display ("                        YOUR_ANSER is right                         ");

      $display ("--------------------------------------------------------------------");

      $display ("");

      @( CLK);    

      @( CLK);    

      $finish; 	

    end

    else begin

      $display ("--------------------------------------------------------------------");

      $display ("                             FAIL!!!                                ");

      $display ("                        YOUR_ANSER is wrong                         ");

      $display ("--------------------------------------------------------------------");

      $display ("");

      @( CLK);    

      @( CLK);    

      $finish; 	

    end

  end

end



endmodule
