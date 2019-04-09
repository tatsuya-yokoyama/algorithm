n, y = map(int, input().split())

count = 0
for i in range(n+1):
    for j in range(n+1):
        k = n - i - j
        if k >= 0:
            sum = 10000*i + 5000*j + 1000*k
            if sum == y:
                print(i, j, k)
                exit()
print('-1 -1 -1')
