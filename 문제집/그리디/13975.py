import sys
import heapq as h

input = sys.stdin.readline

t = int(input().rstrip())
ans = []
while t > 0:
    n = int(input().rstrip())
    arr = list(map(int, input().rstrip().split()))
    inner_ans = 0
    h.heapify(arr)
    while True:
        if len(arr) == 1:
            ans.append(inner_ans)
            break
        a = h.heappop(arr)
        b = h.heappop(arr)
        inner_ans += (a + b)
        h.heappush(arr, a + b)

    t -= 1

for i in ans:
    print(i)