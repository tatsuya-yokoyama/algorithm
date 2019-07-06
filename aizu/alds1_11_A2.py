n = int(input())

A = [[0] * n for _ in range(n)]

for _ in range(n):
    u, k, *v = list(map(int, input().split()))
    for j in v:
        A[u-1][j-1] = 1

for row in A:
    print(' '.join(list(map(str,row))))