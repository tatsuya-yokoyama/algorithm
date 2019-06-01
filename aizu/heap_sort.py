def get_left_index(A, i):
    if H >= 2 * i:
        return 2 * i
    else:
        return None

def get_right_index(A, i):
    if H >= 2 * i + 1:
        return 2 * i + 1
    else:
        return None

def max_heapfy(A, i):
    left = get_left_index(A, i)
    right = get_right_index(A, i)
    largest = i
    if left and A[left] > A[i]:
        largest = left
    if right and A[right] > A[largest]:
        largest = right
    if largest != i:
        # print('max_heapfy.swap', A[i], A[largest])
        A[i], A[largest] = A[largest], A[i]
        max_heapfy(A, largest)

def build_max_heap(A):
    global H
    for i in range(H//2, 0, -1):
        max_heapfy(A, i)        

def heap_sort(A):
    global H
    build_max_heap(A)
    # print('heap_sort')
    # print(A)
    while H > 1:
        # print(H, A[1])
        # print('swap', H, A[1], A[H])
        A[1], A[H] = A[H], A[1]
        H -= 1
        max_heapfy(A, 1)
        # print(H+1, ',' ,A)

H = int(input())
A = [0]
for elem in map(int, input().split()):
    A.append(elem)

heap_sort(A)
print(A[1:])