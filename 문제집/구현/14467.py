from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = [-1] * 11
ans = 0
for _ in range(n):
    a, b = map(int, input().rstrip().split())
    if arr[a] == -1:
        arr[a] = b
    elif arr[a] != b:
        ans += 1
        arr[a] = b
print(ans)
