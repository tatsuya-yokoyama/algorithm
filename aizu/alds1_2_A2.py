def bubble_sort(A):
    count = 0
    while True:
        swapped = False
        for i in range(len(A)-1):
            if A[i+1] < A[i]:
                A[i+1], A[i] = A[i], A[i+1]
                count += 1
                swapped = True
        if not swapped:
            return count

n = int(input())
A = list(map(int, input().split()))
count = bubble_sort(A)
print(*A)
print(count)