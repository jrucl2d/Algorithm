from sys import stdin
input = stdin.readline

t = int(input().rstrip())

for _ in range(t):
    a, b = input().rstrip().split()
    cnt = [0, 0]
    for i in range(len(a)):
        if a[i] != b[i]:
            cnt[int(a[i])] += 1
    if cnt[0] == cnt[1]:
        print(cnt[0])
    else:
        print(max(cnt))
