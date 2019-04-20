def get_parent_key_by(keys, id):
    # print(keys, id % 2, keys[id % 2])
    if id == 1:
        return None
    else:
        return str(keys[id // 2])

def get_left_key_by(keys, id):
    # print(len(keys)+1,  2 * id)
    if len(keys) > 2 * id:
        return str(keys[2 * id])
    else:
        return None

def get_right_key_by(keys, id):
    # print(len(keys)+1,  2 * id + 1)
    if len(keys) > 2 * id + 1:
        return str(keys[2 * id + 1])
    else:
        return None

h = int(input())
keys = [None] * (h + 1)
# print(nodes)
for i, key in enumerate(input().split()):
    # print(i)
    keys[i+1] = int(key)

for i in range(1, h+1):
    msg = 'node ' + str(i) + ': key = ' + str(keys[i]) + ', '
    parent_key = get_parent_key_by(keys, i)
    # print(parent_key)
    if parent_key:
        msg += 'parent key = ' + parent_key + ', '

    left_key = get_left_key_by(keys, i)
    if left_key:
        msg += 'left key = ' + left_key + ', '

    right_key = get_right_key_by(keys, i)
    if right_key:
        msg += 'right key = ' + right_key + ', '
    print(msg)
    # print('-------------')
