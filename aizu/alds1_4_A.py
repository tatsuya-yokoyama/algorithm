
def linear_search(target, nums):
    for num in nums:
        if num == target:
            return True
    return False

n = int(input())
S = list(map(int, input().split()))
q = int(input())
T = list(map(int, input().split()))

count = 0
for t in T:
    if linear_search(t, S):
        count += 1
        
print(count)
