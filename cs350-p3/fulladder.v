module fulladder
  (
    input wire a
    input wire b
    input wire c
    wire o1;
    wire o2;
    output wire s
    output wire cout
  );


  
  assign o1 = a ^ b;
  assign s = o1 ^ c;
  assign o2 = a & b;
  assign o3 = c & a;
  assign cout = o3 | o2;
endmodule
