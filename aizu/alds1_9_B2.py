def get_left_index(A, i):
    if len(A) > 2 * i:
        return 2 * i
    else:
        return None

def get_right_index(A, i):
    if len(A) > 2 * i + 1:
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
        # print('swap ', i, 'and ', largest)
        A[i], A[largest] = A[largest], A[i]
        max_heapfy(A, largest)

def build_max_heap(A):
    global H
    for i in range(H//2, 0, -1):
        max_heapfy(A, i)

def insert(A, a):
    global H
    H += 1
    A.append(a)
    build_max_heap(A)

# build_max_heap(A)
# print(' ', end='')        
# print(*A[1:])

H = 0
A = [0]
while True:
    line = input().split()
    if line[0] == 'insert':
        # print('insert')
        # print(H)
        # print(id(H))
        insert(A, int(line[1]))
    # elif line[0] == 'extract':
    #     max_value = extract_max(A)
    else:
        break

print(*A[1:])