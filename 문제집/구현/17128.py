from sys import stdin
input = stdin.readline
n, q = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))
base = []
ans = 0
for i in range(n):
    inner = 1
    for j in range(4):
        if i + j >= n:
            inner *= arr[i + j - n]
        else:
            inner *= arr[i + j]
    base.append(inner)
    ans += inner
# print(base)
qs = list(map(int, input().rstrip().split()))
for i in qs:
    index = i - 1
    first = index - 4 + n + 1
    for j in range(4):
        start = first + j
        if start >= n:
            ans -= base[start - n]
            ans += (-base[start - n])
            base[start - n] = -base[start - n]
        else:
            ans -= base[start]
            ans += (-base[start])
            base[start] = -base[start]
    print(ans)
