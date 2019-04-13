class Node:
    def __init__(self, val):
        self.val = val
        self.parent = -1
        self.left = -1
        self.right = -1
    
    def get_depth(self):
        if self.parent == -1:
            return 0
        else:
            return nodes[self.parent].get_depth() + 1

    def get_degree(self):
        degree = 0
        if self.left != -1:
            degree += 1
        if self.right != -1:
            degree += 1
        return degree

    def get_height(self):
        # if self.parent != -1:
        #     return 0
        max_height = 0
        if self.left != -1:
            max_height = nodes[self.left].get_height() + 1
            # print("left", max_height)
        if self.right != -1:
            max_height = max(max_height, nodes[self.right].get_height() + 1)
            # print("right", max_height)
        return max_height
    
    def get_sibling(self):
        if self.parent == -1:
            return -1
        
        if nodes[self.parent].left == self.val:
            return nodes[self.parent].right
        else:
            return nodes[self.parent].left

    def get_type(self):
        if self.parent == -1:
            return 'root'
        elif self.left == -1 and self.right == -1:
            return 'leaf'
        else:
            return 'internal node'

n = int(input())
nodes = []
for i in range(n):
    nodes.append(Node(i))


for i in range(n):
    # node
    i, left, right = map(int, input().split())
    nodes[i].left = left
    nodes[i].right = right

    # parent
    if left != -1:
        nodes[left].parent = i
    if right != -1:
        nodes[right].parent = i

    # if i == 4:
    #     print("----------")
    #     print(left, nodes[left].parent, right, nodes[right].parent)
    #     print("----------")
    # for j in range(n):
    #     if j == 8:
    #         print('----------')
    #         print(i, nodes[j].parent)x
    #         print('----------')


# 出力
for i in range(n):
    print('node {val}: parent = {p}, sibling = {s}, degree = {degree}, depth = {depth}, height = {height}, {type}'.format(
        val=i,
        p=nodes[i].parent,
        s=nodes[i].get_sibling(),
        degree=nodes[i].get_degree(),
        depth=nodes[i].get_depth(),
        height=nodes[i].get_height(),
        type=nodes[i].get_type(),
    ))