
def linear_search(key, nums):
    for num in nums:
        if num == key:
            return True
    return False

def binary_search(key, nums):
    # print('binary_serach ' + str(key))
    left = 0
    right = len(nums)
    mid = int((left+right)/2)

    while left < right:
        mid = int((left+right)/2)
        # print(left, mid, right)
        if nums[mid] == key:
            return key
        elif key < nums[mid]:
            right = mid
        else:
            left = mid + 1
    return -1

n = int(input())
S = list(map(int, input().split()))
q = int(input())
T = list(map(int, input().split()))

count = 0
for t in T:
    if binary_search(t, S) > -1:
        count += 1
        
print(count)
