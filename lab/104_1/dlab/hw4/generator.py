end = ""
for i in range(0, 8):
    print("mux _mux%d("%(i))
    for j in range(0, 32):
        print(".in%d(data%d[%d]),"%(j, i, j,), end=end)
    print(".count(count),", end=end)
    print(".out(in%d)"%(i), end=end)
    print(")")
