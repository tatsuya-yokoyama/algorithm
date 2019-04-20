def get_tilt(node):
    if node is None:
        return 0
    return abs(get_val_sum(node.left) - get_val_sum(node.right))

def get_val_sum(node):
    if node is None:
        return 0
    sum = node.val
    if node.left is not None:
        sum += get_val_sum(node.left)
    if node.right is not None:
        sum += get_val_sum(node.right)
    return sum

def pre_order_parse(node):
    if node is None:
        return
    global total_tilt
    total_tilt += get_tilt(node)
    pre_order_parse(node.left)
    pre_order_parse(node.right)

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# root = Node(4)
# root.left = Node(2)
# root.left.left = Node(3)
# root.left.right = Node(5)

# root.right = Node(9)
# root.right.right = Node(7)

# print(4, get_tilt(root))
# print(2, get_tilt(root.left))
# print(9, get_tilt(root.right))
# print(3, get_tilt(root.left.left))
# print(5, get_tilt(root.left.right))
# print("---------")
# total_tilt = 0
# pre_order_parse(root)
# print(total_tilt)

root = Node(1)
root.left = Node(2)

print(1, get_tilt(root))
print(2, get_tilt(root.left))
total_tilt = 0
pre_order_parse(root)
print(total_tilt)

