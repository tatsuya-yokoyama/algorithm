n = int(input())
A = [[0 for i in range(n)] for j in range(n)]

for i in range(n):
    u, k, *v = list(map(int, input().split()))
    for j in v:
        A[int(u)-1][int(j)-1] = 1

for row in A:
    msg = ' '.join(map(str, row))
    print(msg)
