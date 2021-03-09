from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = []
for _ in range(n):
    a, b = map(int, input().rstrip().split())
    arr.append((a, b))
arr.sort(key=lambda x: (-x[1], x[0]))
ans = arr[0][1] - arr[0][0]
for i in range(n - 1):
    time, end = arr[i + 1]
    if ans > end:
        ans = end
        ans -= time
    else:
        ans -= time
if ans < 0:
    print(-1)
else:
    print(ans)
