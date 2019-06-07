class Card:
    def __init__(self, value_str):
        self.value_str = value_str
        self.suit, self.value = list(value_str)
        self.value = int(self.value)

def bubble_sort(A):
    flag = 1
    swap_count = 0
    while flag:
        flag = 0
        print('len(A) - 1)', len(A) - 1)
        for i in range(len(A) - 1):
            print(i)
            current_node = A[i]
            next_node = A[i+1]
            if current_node > next_node:
                # print('swap:', A[i], A[i+1])
                A[i], A[i+1] = A[i+1], A[i]
                swap_count += 1
                flag = 1 
    return swap_count 

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
A = []
for value_str in input().split():
    A.append(Card(value_str))

for a in A:
    print(a.value_str)   


# A = list(map(int, input().split()))

# swap_count = selection_sort(A)
# print(' '.join(map(str, A)))
# print(swap_count)

