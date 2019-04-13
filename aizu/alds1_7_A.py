class Node:
    def __init__(self):
        self.parent = -1
        self.left = -1
        self.right = -1

    def get_depth(self):
        d = 0
        u = self.
        while nodes[u].parent != -1:
            u = nodes[u].parent
            d += 1
        return d

    def get_children(self):
        children = []
        c = nodes[u].left
        while c != -1:
            children.append(c)
            c = nodes[u].right
        return children

n = int(input())
nodes = []
for i in range(n):
    nodes.append(Node())
for i in range(n):
    i, degree, *children = map(int, input().split())
    if degree > 0:
        nodes[i].left = children[0]
        for index, child in enumerate(children):
            nodes[child].parent = i
            if index != degree - 1:
                nodes[child].right = children[index+1]

for i in range(n):
    parent = nodes[i].parent
    type = 'internal node'
    if nodes[i].parent == -1:
        type = 'root'
    elif nodes[i].left == -1:
        type = 'leaf'
    d = get_depth(i)
    msg = 'node ' + str(i) + ':parent = ' + str(parent) + ', depth = ' + str(d) + ', ' + type + ', ['
    msg += ', '.join(get_children(i))
    msg += ']'
    print(msg)   
