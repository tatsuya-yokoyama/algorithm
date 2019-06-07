A, B = map(int, input().split())
s = 0
if A > B:
    s = A + A - 1
elif B > A:
    s = B + B - 1
else:
    s = A + A
print(s)

# s = 0
# for _ in range(2):
#     if A >= B:
#         s += A
#         A -= 1
#     else:
#         s += B
#         B -= 1

