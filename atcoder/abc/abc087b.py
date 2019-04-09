a,b,c,x = map(int, [input() for i in range(4)])

count = 0
for i in range(a+1):
    for j in range(b+1):
        for k in range(c+1):
            s = 500 * i + 100 * j + 50 * k
            if s == x:
                count +=1
            # print(s)
print(count)