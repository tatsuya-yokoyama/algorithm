stack = []
for char in input().split():
    if char in ['+', '-', '*']:
        a = int(stack.pop())
        b = int(stack.pop())
        if char == '+':
            stack.append(a + b)
        elif char == '-':
            stack.append(b - a)
        else:
            stack.append(a * b)
    else:
        stack.append(char)
print(stack.pop())