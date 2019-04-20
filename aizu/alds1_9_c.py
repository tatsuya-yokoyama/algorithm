
# http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2432526#1
# http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2197496#1
class PriorityQueue:
    INIT_VALUE = -1
    MAX_SIZE = 2000001

    def __init__(self):
        self.heap = [PriorityQueue.INIT_VALUE] * PriorityQueue.MAX_SIZE
        self.size = 0

    def insert(self, key):
        self.size += 1
        self.heap[self.size] = key
        i = self.size
        while i > 1:
            parent_index = i // 2
            if parent_index == 0:
                break
            if self.heap[parent_index] < self.heap[i]:
                tmp = self.heap[i]
                self.heap[i] = self.heap[parent_index]
                self.heap[parent_index] = tmp
                i = parent_index
            else:
                break

    def extract_max(self):
        max_value = self.heap[1]
        self.heap[1] = self.heap[self.size]
        self.heap[self.size] = PriorityQueue.INIT_VALUE
        self.size -= 1
        self.max_heapfy(1)
        return max_value

    def max_heapfy(self, i):
        left = self.get_left(i)
        right = self.get_right(i)
        largest = i
        if left and self.heap[left] > self.heap[i]:
            largest = left
        if right and self.heap[right] > self.heap[largest]:
            largest = right
        if largest != i:
            tmp = self.heap[i]
            self.heap[i] = self.heap[largest]
            self.heap[largest] = tmp
            self.max_heapfy(largest)

    def print_queue(self):
        for i in range(1, self.size + 1):
            print(self.heap[i])

    def get_left(self, i):
        if 2 * i <= self.size:
            return 2 * i
        else:
            None

    def get_right(self, i):
        if 2 * i + 1 <= self.size:
            return 2 * i + 1
        else:
            None

q = PriorityQueue()
while True:
    line = input().split()
    if line[0] == 'insert':
        q.insert(int(line[1]))
        # print(A)
    elif line[0] == 'extract':
        max_value = q.extract_max()
        print(max_value)
    else:
        break