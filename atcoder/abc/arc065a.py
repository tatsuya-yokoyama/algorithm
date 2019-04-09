s = input()[::-1]
words_r = ['eraser'[::-1], 'erase'[::-1], 'dreamer'[::-1], 'dream'[::-1]]
for word_r in words_r:
    s = s.replace(word_r, '')

if s:
    print('NO')
else:
    print('YES')