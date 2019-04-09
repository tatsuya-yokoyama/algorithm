n = int(input())

prev_t = 0
prev_x = 0
prev_y = 0

for i in range(n):
    t, x, y = map(int, input().split())

    dt = t - prev_t
    dx = abs(x - prev_x)
    dy = abs(y - prev_y)
    dist = dx + dy

    if dist > dt:
        print('No')
        exit()
    
    if dt % 2 != dist % 2:
        print('No')
        exit()

print('Yes')