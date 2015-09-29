
a = [0, 1, 1]

for i in range(3, 20001):
    a.append(a[i-1] + a[i-2])


