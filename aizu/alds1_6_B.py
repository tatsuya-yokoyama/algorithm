def partition(A, p, r):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return i + 1

n = int(input())
A = list(map(int, input().split()))
q = partition(A, 0, n-1)
A[q] = '[' + str(A[q]) + ']'
print(*A)
# for i, a in enumerate(A):
#     if i == q:
#         print('[', end='')
#     print(a, end='')
#     if i == q:
#         print(']', end='')
#     if i < len(A)-1:
#         print(' ', end='')
# print('')