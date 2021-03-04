from sys import stdin
input = stdin.readline
t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    a = input().rstrip()
    b = input().rstrip()
    cnt = [0, 0]
    for i in range(n):
        if a[i] == b[i]:
            continue
        if a[i] == 'B':
            cnt[0] += 1
        else:
            cnt[1] += 1
    print(max(cnt))
