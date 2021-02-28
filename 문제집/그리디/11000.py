from sys import stdin
import heapq
input = stdin.readline

n = int(input().rstrip())

arr = []
for _ in range(n):
    a, b = map(int, input().rstrip().split())
    arr.append((a, b))

arr.sort(key=lambda x : (x[0], x[1]))

ans = [arr[0][1]]
heapq.heapify(ans)

for _ in range(1, n):
    start, end = arr[_]
    if ans[0] <= start:
        heapq.heappop(ans)
    heapq.heappush(ans, end)

print(len(ans))