from sys import stdin
input = stdin.readline
n, a, d = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))
ans = 0
for now in arr:
    if now == a:
        ans += 1
        a += d
print(ans)
