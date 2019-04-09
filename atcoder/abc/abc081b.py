n = input()
a_str = input().split()
a = list(map(int, a_str))
count = 0
should_continue = True
while should_continue:
    # print("i")
    for i, num in enumerate(a):
        # print(num)
        if num%2 == 0:
            num //= 2
            a[i] = num
            # print(num)
        else:
            should_continue = False
    if should_continue:
        count+=1
print(count)