def selection_sort(A):
    count = 0
    for i in range(len(A)):
        min_value = A[i]
        min_value_index = i
        print('- i:', i, 'A[i]', A[i], '-')
        for j in range(i, len(A)):
            print('j:', j, 'A[j]:', A[j])
            count += 1
            if A[j] < min_value:
                min_value = A[j]
                min_value_index = j
        print('min_value', min_value, 'min_value_index', min_value_index)
        if i != min_value_index:
            A[i], A[min_value_index] = A[min_value_index], A[i]
            print('swap!', A)
        else:
            print('not swap', A)
        
    return count

A = [10,30,8,4,2]
count = selection_sort(A)
print(len(A))
print(A)
print(count)