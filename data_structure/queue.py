class Queue():
    def __init__(self):
        self.length = 10 ** 6
        self.q_list = [None] * (self.length + 1)
        self.head = 0
        self.tail = 0
        
    def enqueue(self, x):
        if self.is_full():
#             print('is_full')
            raise Exception
#         print('exec enqueue')
        self.q_list[self.tail] = x
        if self.tail == self.length - 1:
            self.tail = 0
        else:
            self.tail += 1
            
    def dequeue(self):
        if self.is_empty():
            raise Exception
        x = self.q_list[self.head]
        if self.head == self.length - 1:
            self.head = 0
        else:
            self.head += 1
        return x
    
    def is_empty(self):
        if self.head == self.tail:
            return True
        else:
            return False
    
    def is_full(self):
#         print('head', self.head, 'tail', self.tail)
        if self.head == self.tail + 1 or (self.head == 0 and self.tail == self.length-1):
            return True
        else:
            return False