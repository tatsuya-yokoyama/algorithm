class MyHash():
    def __init__(self):
        self.m = 10 ** 7
        self.hash_table = [None] * self.m
    
    def h1(self, k):
        return k % self.m
    
    def h2(self, k):
        return k % (self.m-1)
    
    def h_total(self, k, i):
        return (self.h1(k) + i * self.h2(k)) % self.m
    
    def v_int(self, v_str):
        num_sum = 0
        for i, c in enumerate(v_str):
            num = None
            if c == 'A':
                num = 1
            elif c == 'C':
                num = 2
            elif c == 'G':
                num = 3
            else:
                num = 4
            num_sum += num * 10 ** i
        return num_sum
    
    def insert(self, v_str):
        v_int = self.v_int(v_str)
        for i in range(10):
            index = self.h_total(v_int, i)

            if self.hash_table[index] is None:
                # print('inserted to ', index)
                self.hash_table[index] = v_str
                return
            elif self.hash_table[index] == v_str:
                # print('already exists')
                break
            else:
                # print('collision!')
                continue
                
    def find(self, v_str):
        v_int = self.v_int(v_str)
        for i in range(10):
            index = self.h_total(v_int, i)
            if self.hash_table[index] is None:
                return False
            elif self.hash_table[index] == v_str:
                return True
            else:
                # print('collision')
                continue
        return False

h = MyHash()
n = int(input())
for i in range(n):
    command, val = input().split()
    if command == 'insert':
        h.insert(val)
    else:
        if h.find(val):
            print('yes')
        else:
            print('no')