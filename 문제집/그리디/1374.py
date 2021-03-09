from sys import stdin
import heapq as h
input = stdin.readline
n = int(input().rstrip())
arr = []
for _ in range(n):
    a, b, c = map(int, input().rstrip().split())
    arr.append((b, c))
arr.sort(key=lambda x: (x[0], x[1]))
ans = [arr[0][1]]
h.heapify(ans)
for i in range(1, n):
    (start, end) = arr[i]
    if ans[0] <= start:
        h.heappop(ans)
    h.heappush(ans, end)
print(len(ans))
