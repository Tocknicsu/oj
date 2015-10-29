print("module mux(")
for i in range(0, 32):
    print("\tinput [7:0] in%d,"%(i))
print("\tinput [4:0] cnt,")
print("\toutput [7:0] out")
print(");")
print("reg [7:0] value;")
print("assign out=value;")
print("always @(*) begin")
print("\tcase (cnt)")
for i in range(0, 32):
    print("\t\t%d: value<=in%d;"%(i, i))
print("\tendcase")
print("end")
print("endmodule")