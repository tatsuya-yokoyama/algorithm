class Node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

class Tree:

    def __init__(self):
        self.root = None
        self.inorder = []


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
                return node
            elif key < node.key:
                node = node.left
            else:
                node = node.right
        return None

    def get_next_node(self, node):
        self.inorder = []
        print_in_order(self.root)
        is_current_node = False
        next_node = None
        next_node_key = None
        for i in self.inorder:
            if i ==  node.key:
                is_current_node = True
            if is_current_node:
                next_node_key = i
        return self.find(next_node_key)

    def delete(self, node):
        if node is None:
            return
        print('delete-----------')
        print(node)
        print(node.key)
        # nodeが子を持たない場合
        if node.left is None and node.right is None:
            print('no child:', node.key)
            if node.parent.left.key == node.key:
                # この子が左子の場合
                node.parent.left == None
            else:
                # この子が右子の場合
                node.parent.right == None

        elif node.left is not None and node.right is not None:
            
            # nodeが子を2つ持つ場合
            next_node = self.get_next_node(node)
            print('delete:', next_node.key, node.key)
            node.key = next_node.key
            
            self.delete(next_node)
        else:
            print('-------------------------------------')
            print('only one child:', node.key)
            print('only one child:', node.parent.val)
            # このノードの子供を特定(左なのか右なのか)
            child = None
            if node.left is not None:
                # 左側に子供を持ってる場合
                child = node.left
            else:
                child = node.right

            if node.parent.left.key == node.key:
                # この子が左子の場合
                node.parent.left = child
            else:
                # この子が右子の場合
                node.parent.right = child
        
    def print_in_order(self, node):
        if node is None:
            return
        self.print_in_order(node.left)
        print(' ' + str(node.key), end='')
        self.inorder.append(node.key)
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
        if tree.find(key):
            print('yes')
        else:
            print('no')
    elif line[0] == 'delete':
        print("current tree----")
        print(tree.root.key)
        print(tree.root.left.key)
        print(tree.root.left.right.key)
        print("current tree----")
        key = int(line[1])
        node = tree.find(key)
        tree.delete(node)