class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
class Tree:
    def __init__(self):
        self.root = None

    def get_max_depth(self, node):
        if node is None:
            return 0
        max_depth_left = self.get_max_depth(node.left)
        max_depth_right = self.get_max_depth(node.right)
        return max(max_depth_left, max_depth_right) + 1


    def find(self, val):
        node = self.root
        while node is not None:
            if val == node.val:
                return node
            elif val < node.val:
                node = node.left
            else:
                node = node.right
        return None

    def insert(self, node):
        print('insert', node.val, '-----------')
        p = None
        x = self.root        
        while x is not None:
            p = x
            if node.val <= x.val:
                x = x.left
            else:
                x = x.right
        x = node

        if p is None:
            print('rootに設定')
            self.root = node
        else:
            # insertするnodeを親のleftかrightに設定
            print(str(node.val), str(p.val))
            if node.val <= p.val:
                print('leftに設定')
                p.left = node
            else:
                print('rightに設定')
                p.right = node

tree = Tree()
tree.root = Node(3)
tree.root.left = Node(9)
tree.root.right = Node(20)
tree.root.right.left = Node(15)
tree.root.right.right = Node(7)

print('max_depth', tree.get_max_depth(tree.root))

# tree.insert(Node(9))
# tree.insert(Node(20))
# tree.insert(Node(15))
# tree.insert(Node(7))

# print('-----')
# print(tree.root.val)
# print(tree.root.left.val)
# print(tree.root.right.val)
