module halfadd
(
   input wire a
   input wire b 
   output wire o0
   output wire o1

);

assign o0 = a ^ b;
assign o1 = a & b;
endmodule
