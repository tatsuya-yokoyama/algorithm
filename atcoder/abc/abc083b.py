n, a, b = map(int, input().split())
sum = 0
for i in range(n+1):
    i_str = list(str(i))
    # print(i_str)
    num_sum = 0
    for num_str in i_str:
        num_sum += int(num_str)
    if num_sum >= a and num_sum <= b:
        sum += i
print(sum)