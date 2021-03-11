from sys import stdin
import heapq as h
input = stdin.readline
n = int(input().rstrip())
arr = []
for _ in range(n):
    p, d = map(int, input().rstrip().split())
    arr.append((p, d))
arr.sort(key=lambda x: x[1])
ans = []
for val, time in arr:
    h.heappush(ans, val)
    if len(ans) > time:
        h.heappop(ans)
print(sum(ans))
