def binary_search(key, nums):
    # print('binary_serach ' + str(key))
    left = 0
    right = len(nums)
    mid = int((left+right)/2)

    while left < right:
        mid = int((left+right)/2)
        # print(left, mid, right)
        if nums[mid] == key:
            return mid
        elif key < nums[mid]:
            right = mid
        else:
            left = mid + 1
    return -1


nums = sorted(nums)
print(len(nums))

for i in range(len(nums)):
    num = nums[i]
    key = target - num
    index = binary_search(key, nums)
    if index > -1:
        print(i, index)
        exit()
