def selection_sort(A):
    swap_count = 0
    for i in range(len(A)):
        min_j = i
        for j in range(i, len(A)):
            if A[j] < A[min_j]:
                min_j = j
        if i != min_j:
            A[i], A[min_j] = A[min_j], A[i]
            swap_count += 1
    return swap_count

N = int(input())
A = list(map(int, input().split()))

swap_count = selection_sort(A)
print(' '.join(map(str, A)))
print(swap_count)

#