n = input()
a = map(int, input().split())

alice_score = 0
bob_score = 0
for index, i in enumerate(sorted(a, reverse=True)):
    if index % 2 == 0:
        alice_score += i
    else:
        bob_score += i
print(alice_score-bob_score)