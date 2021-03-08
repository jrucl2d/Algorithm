from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = input().rstrip()

only_b = arr.split("R")
cnt = 0
for i in range(1, len(only_b) - 1):
    cnt += len(only_b[i])
if only_b[0] != '' and only_b[len(only_b) - 1] != '':
    cnt += min(len(only_b[0]), len(only_b[len(only_b) - 1]))

only_r = arr.split("B")
cnt2 = 0
for i in range(1, len(only_r) - 1):
    cnt2 += len(only_r[i])
if only_r[0] != '' and only_r[len(only_r) - 1] != '':
    cnt2 += min(len(only_r[0]), len(only_r[len(only_r) - 1]))

print(min(cnt, cnt2))
