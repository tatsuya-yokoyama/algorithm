class Node:
    def __init__(self, id):
        self.id = id
        self.left = None
        self.right = None

root_node = None
n = int(input())
for i in range(n):
    id, left, right = list(map(int, input().split()))
    node = Node(id)
    if left > -1:
        node.left = left
    if right > -1:
        node.right = right
    if id == 0:
        root_node = node

print(vars(root_node))