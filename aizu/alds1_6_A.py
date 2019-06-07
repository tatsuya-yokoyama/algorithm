# def counting_sort(A):
#     # init
#     bucket = []
#     for i in range(10000):
#         bucket.append(0)

#     for a in A:
#         bucket[a] += 1

#     k = 0
#     # これだとO(kn)になってしまう！
#     for i in range(10000):
#         for j in range(bucket[i]):
#             A[k] = i
#             k += 1

def counting_sort(A, k):
    # init
    bucket = [0] * (k+1)
    B = [0] * n

    # count
    for a in A:
        bucket[a] += 1

    # sum
    for i in range(1, k+1):
        bucket[i] = bucket[i] + bucket[i-1]

    

    for a in reversed(A):
        B[bucket[a]] = a
        B[bucket[a]] -= 1

    return B

n = int(input())
A = list(map(int, input().split()))

B = counting_sort(A, 10000)

print(*B)