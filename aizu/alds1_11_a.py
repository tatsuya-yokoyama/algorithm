n = int(input())
A = [[0 for i in range(n)] for j in range(n)]

for i in range(n):
    u, k, *v = list(map(int, input().split()))
    for j in v:
        A[int(u)-1][int(j)-1] = 1
        # A[int(j)-1][int(u)-1] = 1

for row in A:
    msg = ' '.join(map(str, row))
    # print(msg)

d = [-1] * n
f = [-1] * n

t = 0

# # recursive
# def dfs(u):
#     global t
#     # print('visit:', str(u), str(t))
#     t += 1
#     d[u] = t
#     for i in range(len(A[u])):
#         if A[u][i] == 1 and d[i] == -1:
#             dfs(i)
#     t += 1
#     f[u] = t
            

def get_next(u):
    for i in range(len(A[u])):
        if A[u][i] == 1 and d[i] == -1:
            return i
    return None

def dfs(u):
    global t
    s = []
    s.append(u)
    d[u] = t
    while len(s) > 0:
        p = s[-1]
        v = get_next(p)
        # print(p, 'next:', v)
        # t += 1
        # d[p] = t
        # print('poped:', p)
        
        if v is not None:
            
            if d[v] == -1:
                t += 1
                d[v] = t
                s.append(v)
                # print('[append:', v, 'at', t)
        else:
            t += 1
            # print('complete:', p, 'at', t)
            s.pop()
            f[p] = t


# def dfs(u):
#     s = []
#     t = 0
#     s.append(u)
    
#     while len(s) > 0:
#         p = s.pop()
#         print('init', str(p), d[p], t)
#         if d[p] > -1:
#             print('完了')
#             t += 1
#             f[p] = t
#         else:
#             t += 1
#             d[p] = t
#             print('---visit:', str(p), str(t), 'at', t)
#             has_node = False
#             for i in range(len(A[p])):
#                 if A[p][i] == 1 and d[i] == -1:
#                     print('reserve:', str(i))
#                     has_node = True
#                     s.append(i)
#                     break
#             if not has_node:
#                 t += 1
#                 f[p] = t
#         # print('H_complete:', str(p), str(t))
            


t = 0
for i in range(n):
    if d[i] == -1:
        t += 1
        # print('start from:', str(i))
        dfs(i)


for i in range(n):
    print(str(i+1), str(d[i]), str(f[i]))