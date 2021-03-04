from sys import stdin
input = stdin.readline

n = int(input().rstrip())
arr = []
for _ in range(n):
    a = int(input().rstrip())
    arr.append(a)

ans = 0
before = arr[n - 1]
for i in range(n - 2, -1, -1):
    now = arr[i]
    if now >= before:
        minus = now - before + 1
        ans += minus
        arr[i] -= minus
    before = arr[i]
print(ans)
