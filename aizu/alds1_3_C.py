class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, node):
        if self.head is None:
            print('insert pattern1')
            self.head = node
            self.tail = node
        else:
            print('insert pattern2')
            node.prev = self.head
            self.tail.next = node
            self.tail = self.tail.next

    def delete(self, key):
        node = self.head
        while node is not None:
            if node.val == key:
                node.prev.next = node.next
                node.prev.next.prev = node.prev
            else:
                node = node.next

    def show(self):
        node = self.head
        while node is not None:
            print(str(node.key) + ' ', end='')
            node = node.next
        print('')


class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

n = int(input())

linked_list = LinkedList()

for i in range(n):
    line = input().split()
    command = line[0]
    if command == 'insert':
        key = int(line[1])
        linked_list.insert(Node(key))
        linked_list.show()
    elif command == 'delete':
        key = int(line[1])
        linked_list.delete(key)
        linked_list.show()
    elif command == 'deleteFirst':
        pass
    elif command == 'deleteLast':
        pass
