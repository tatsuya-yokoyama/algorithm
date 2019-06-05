class SinglyLinkedListNode:

    def __init__(self, key):
        self.key = key
        self.next = None

class SinglyLinkedList:

    def __init__(self):
        self.head = None

    def insert(self, key):
        node = SinglyLinkedListNode(key)
        
        # 空の場合
        if self.head is None:
            self.head = node
            return
        
        node.next = self.head
        self.head = node
        
    def delete(self, key):
        node = self.head
        prev_node = None
        while node is not None:
            if node.key == key:
                prev_node.next = node.next
            prev_node = node
            node = node.next
        
    def delete_first(self):
        if self.head is None:
            return
        
        self.head = self.head.next
            
    def show(self):
        node = self.head
        i = 0
        while node is not None:
            print('i:{}, key:{}'.format(i, node.key))
            node = node.next
            i += 1