class Node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

class Tree:

    def __init__(self):
        self.root = None

    def insert(self, node):
        y = None
        x = self.root

        while x is not None:
            y = x
            if node.key <= x.key:
                x = x.left
            else:
                x = x.right

        if y is None:
            self.root = node
        elif node.key < y.key:
            y.left = node
        else:
            y.right = node

    def find(self, key):
        node = self.root
        while node is not None:
            if node.key == key:
                return 'yes'
            elif key < node.key:
                node = node.left
            else:
                node = node.right
        return 'no'

    def delete(self, node):
        # nodeが子を持たない場合
        if node.left is None and node.right is None:
            if node.parent.left.key == node.left.key:
                node.parent.left == None
            else:
                node.parent.right == None
        elif node.left is not None and node.right is not None:
            # nodeが子を2つ持つ場合
            pass
        else:
            # nodeが子を1つ持つ場合
            # 左側に子を持つ場合
            if node.left is not None:
                node.left.parent = node.parent
                pass
            # 右側に子を持つ場合
            if node.right is not None:
                pass

        
        

    def print_in_order(self, node):
        if node is None:
            return
        self.print_in_order(node.left)
        print(' ' + str(node.key), end='')
        self.print_in_order(node.right)

    def print_pre_order(self, node):
        if node is None:
            return
        print(' ' + str(node.key), end='')
        self.print_pre_order(node.left)
        self.print_pre_order(node.right)

tree = Tree()
m = int(input())
for i in range(m):
    line = input().split()
    if line[0] == 'print':
        tree.print_in_order(tree.root)
        print('')
        tree.print_pre_order(tree.root)
        print('')
    elif line[0] == 'insert':
        key = int(line[1])
        tree.insert(Node(key))
    elif line[0] == 'find':
        key = int(line[1])
        print(tree.find(key))