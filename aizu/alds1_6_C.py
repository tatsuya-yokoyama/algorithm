import copy

def merge(A, left, mid, right):
    SENTINEL = 10 ** 9
    L = A[left:mid] + [Card('D', SENTINEL)]
    R = A[mid:right] + [Card('D', SENTINEL)]
    # print('L', L)
    # print('R', R)

    i = 0
    j = 0
    for k in range(left, right):
        # print(vars(L[i]))
        # print(vars(R[i]))
        if L[i].number <= R[j].number:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    # print('l', left, 'm', mid, 'r', right, A, count)

def merge_sort(A, left, right):
    # print('merge_sort', left, right)
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)
def partition(A, p, r):
    x = A[r].number
    i = p - 1
    for j in range(p, r):
        if A[j].number <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return i + 1

class Card:
    def __init__(self, suit, number):
        self.suit = suit
        self.number = number

def quick_sort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quick_sort(A, p, q-1)
        quick_sort(A, q+1, r)

n = int(input())
A = []
for i in range(n):
    suit, number = input().split()
    A.append(Card(suit, int(number)))
# print(A)

merge_sorted_A = copy.deepcopy(A)

merge_sort(merge_sorted_A, 0, len(merge_sorted_A))
# print('merge_sort')
# for card in merge_sorted_A:
#     print(card.suit, card.number)

# print('quick_sort')
quick_sorted_A = copy.deepcopy(A)
quick_sort(quick_sorted_A, 0, len(quick_sorted_A)-1)

# for card in quick_sorted_A:
#     print(card.suit, card.number)

is_stable = True
for i in range(len(A)):
    if not (quick_sorted_A[i].suit == merge_sorted_A[i].suit):
        is_stable = False
        break

if is_stable:
    print('Stable')
else:
    print('Not stable')

for card in quick_sorted_A:
    print(card.suit, card.number)
