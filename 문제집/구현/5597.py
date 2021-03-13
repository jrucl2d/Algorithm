from sys import stdin
input = stdin.readline
did = [False] * 30
for i in range(28):
    n = int(input().rstrip())
    did[n - 1] = True
for i in range(30):
    if not did[i]:
        print(i + 1)