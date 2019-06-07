S = list(map(int,input()))
# print(S)

# 0始まり
# 01010101...
count_0 = 0
for i, s in enumerate(S):
    if i % 2 == 0:
        if s!= 0:
            count_0 += 1
    else:
        if s!= 1:
            count_0 += 1
# print(count_0)

# 1始まり
# 10101010...
count_1 = 0
for i, s in enumerate(S):
    if i % 2 == 0:
        if s!= 1:
            count_1 += 1
    else:
        if s!= 0:
            count_1 += 1
# print(count_1)
print(min(count_0, count_1))