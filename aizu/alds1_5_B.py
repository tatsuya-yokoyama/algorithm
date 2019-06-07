def merge(A, left, mid, right):
    global count
    SENTINEL = 10 ** 9
    L = A[left:mid] + [SENTINEL]
    R = A[mid:right] + [SENTINEL]
    print('L', L)
    print('R', R)

    i = 0
    j = 0
    for k in range(left, right):
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    print('l', left, 'm', mid, 'r', right, A, count)

def mergeSort(A, left, right):
    print('mergeSort', left, right)
    if left + 1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

n = int(input())
A = list(map(int, input().split()))
count = 0
mergeSort(A, 0, n)

print(' '.join(list(map(str, A))))
print(count)
