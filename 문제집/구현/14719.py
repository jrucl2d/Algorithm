from sys import stdin
input = stdin.readline
n, m = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))

ans = 0
for i in range(1, m - 1):
    now = arr[i]
    left, right = -1, -1
    for j in range(0, i):
        left = max(left, arr[j])
    for j in range(i + 1, m):
        right = max(right, arr[j])
    the_height = min(left, right)
    if the_height > now:
        ans += (the_height - now)
print(ans)
