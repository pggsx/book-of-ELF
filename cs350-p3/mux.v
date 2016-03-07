module multiplexer
  (
   input wire i0 
   input wire i1
   input wire i2
   input wire i3
   input wire s1
   input wire s0
   output wire o
  );
 wire o0;
 wire 01;

 wire pa;
 wire pb;
 wire pc;
 wire pd;

 wire a;
 wire b;
 wire c;
 wire d;



assign o = o0 | o1;
assign o0 = pa | pb;
assign o1 = pc | pd;
assign pa = a &  ~s0;
assign pb = b &  s0;
assign pc = b &  ~s0;
assign pd = b &  s0;
assign a = i0 & ~s1;
assign c = i0 & ~s1;
assign d = i0 & s1;
endmodule

