
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

N = int(input())
A = list(map(int, input().split()))

swap_count = bubble_sort(A)
print(' '.join(map(str, A)))
print(swap_count)

# 