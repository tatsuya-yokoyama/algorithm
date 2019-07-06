n = int(input())

A = [[0] * n for _ in range(n)]

for _ in range(n):
    u, k, *v = list(map(int, input().split()))
    for j in v:
        A[u-1][j-1] = 1

# for row in A:
#     print(' '.join(list(map(str,row))))

t = 0
d = [None] * n
f = [None] * n

def dfs_stack(root):
    global t
    stack = []
    stack.append(root)
    while stack:

        # 一番最後の要素をなめる
        u = stack[-1]

        # 未訪問の場合は訪問済みにする
        if d[u] is None:
            t += 1
            d[u] = t

        # 次の訪問先を探す
        has_next_node = False
        for v in range(n):
            if A[u][v] == 1 and d[v] is None:
                stack.append(v)
                has_next_node = True
                break

        # 次の訪問先がなければ訪問終了
        if not has_next_node:
            t += 1
            # スタックから取り出す
            stack.pop()

            # 時刻を記録
            f[u] = t
            
for i in range(n):
    if d[i] is None:
        dfs_stack(i)

for i in range(n):
    print(i+1, d[i], f[i])        