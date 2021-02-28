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
for i in range(1, n):
    start, end = arr[i]
    if ans[0] <= start: # end에 대해서도 정렬이 되어있으므로
        heapq.heappop(ans) # 지금 보고 있는 now가 heap의 최소값보다 무조건 큰 것이 만족된다.
        heapq.heappush(ans, end)
    else:
        heapq.heappush(ans, end)

print(len(ans))
