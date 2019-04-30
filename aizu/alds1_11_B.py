# input
n = int(input())
A = [[0 for i in range(n)] for j in range(n)]

for i in range(n):
    u, k, *v_list = list(map(int, input().split()))
    for v in v_list:
        A[u-1][v-1] = 1


# init
d = [0] * n
f = [0] * n
t = 0

def dfs_recursive(root):
    global t
    t += 1
    u = root
    d[u] = t
    for v in range(n):
        if A[u][v] == 1 and d[v] == 0:
            dfs_recursive(v)
    t += 1
    f[u] = t


def dfs_stack(root):
    global t
    stack = []
    stack.append(root)

    while len(stack) > 0:
        # スタックから要素を取り出す
        u = stack[-1]

        # 未訪問の場合は訪問済みにする
        if d[u] == 0:
            t += 1
            d[u] = t

        # 次の訪問先を探す
        next_node = None
        for v in range(n):
            print(u, v, A[u][v])
            if A[u][v] == 1 and d[v] == 0:
                next_node = v
                break

        # 次の訪問先があればスタックに追加、なければ訪問終了
        if next_node is None:
            t += 1
            stack.pop()
            f[u] = t
        else:
            stack.append(next_node)

# dfs
for i in range(n):
    if d[i] == 0:
        dfs_recursive(i)

# output
for i in range(n):
    print(i+1, d[i], f[i])