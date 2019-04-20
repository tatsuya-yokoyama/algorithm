def get_parent(A, i):
    if i == 1:
        return None
    else:
        return i // 2

def get_left(A, i):
    if len(A) > 2 * i:
        return 2 * i
    else:
        return None

def get_right(A, i):
    if len(A) > 2 * i + 1:
        return 2 * i + 1
    else:
        return None

A = [-1] * 2000000
H = 0

def insert(A, key):
    global H
    H += 1
    A[H] = key
    i = H
    while i > 1:
        # print(i)
        parent = get_parent(A, i)
        if parent is None:
            break
        if A[parent] < A[i]:
            # print('swap', i, parent, A[i], A[parent])
            tmp = A[i]
            A[i] = A[parent]
            A[parent] = tmp
            i = parent
        else:
            break

def max_heapfy(A, i):
    left = get_left(A, i)
    right = get_right(A, i)
    largest = i
    if left and A[left] > A[i]:
        largest = left
    if right and A[right] > A[largest]:
        largest = right
    if largest != i:
        tmp = A[i]
        A[i] = A[largest]
        A[largest] = tmp
        max_heapfy(A, largest)

def extract_max(A):
    global H
    max_value = A[1]
    A[1] = A[H]
    A[H] = -1
    H -= 1
    max_heapfy(A, 1)
    return max_value

# Heap heap ヒープの実装はここを参考にした
# http://ikapblg.blog.fc2.com/blog-entry-57.html

def print_heap(A):
    for index, elem in enumerate(A):
        if index == 0:
            continue
        if elem == -1:
            break
        print(elem)

while True:
    line = input().split()
    if line[0] == 'insert':
        insert(A, int(line[1]))
        # print(A)
    elif line[0] == 'extract':
        max_value = extract_max(A)
        print(max_value)

    else:
        # print('end:')
        # print_heap(A)
        break