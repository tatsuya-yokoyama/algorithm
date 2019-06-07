def insertion_sort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v

def shell_sort(A, n):
    global G
    print("-----------")
    
    h = 1
    while True:
        G.append(h)
        h += 3
        if h > n:
            break
    # print(G)
    global m
    for g in reversed(G):
        m += 1
        insertion_sort(A, n, g)

n = int(input())
A = []
cnt = 0
m = 0
G = []
for i in range(n):
    A.append(int(input()))

shell_sort(A, n)

print('--')
print(m)
print('G')
print(G)
print('A')
for a in A:
    print(a)