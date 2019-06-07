n, m = map(int, input().split())
# print('n:', n, 'm:', m)
A = [[0 for i in range(n)] for j in range(n)]
visited = [0 for i in range(n)]

for i in range(m):
    u, v = list(map(int, input().split()))
    # print(u, v)
    A[u][v] = 1
    A[v][u] = 1
# print(A)

q = int(input())
# print('q:', q)


def dfs(s):
    # print('visit', s)
    if s is None:
        return
    visited[s] = 1
    for v in range(n):
        # print('candidate:', v)
        if A[s][v] == 1 and visited[v] == 0:
            dfs(v)

def can_go(s, t):
    # print(s, '->', t, '----------')
    global visited
    visited = [0 for i in range(n)]
    dfs(s)
    # print(visited)
    if visited[t] == 1:
        return True
    else:
        return False

for i in range(q):
    s, t = map(int, input().split())
    if can_go(s, t):
        print('yes')
    else:
        print('no')
