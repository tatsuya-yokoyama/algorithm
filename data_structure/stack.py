class Stack:
    def __init__(self):
        self.top = 0
        self.max_size = 3
        self.stack_array = [None] * self.max_size

    def push(self, x):
        if self.is_full():
            raise Exception('stack is full')
        self.stack_array[self.top] = x
        self.top += 1
        
    def pop(self):
        if self.is_empty():
            raise Exception('stack is empty')
        self.top -= 1
        return self.stack_array[self.top+1]
    
    def is_full(self):
        if self.top == self.max_size:
            return True
        else:
            return False
        
    def is_empty(self):
        if self.top == 0:
            return True
        else:
            return False