import sys
import heapq
n = int(sys.stdin.readline().rstrip())

Mq = []
mq = []

for _ in range(n):
    a = int(sys.stdin.readline().rstrip())
    if len(Mq) == len(mq):
        heapq.heappush(Mq, -a)
    else:
        heapq.heappush(mq, a)
    if len(mq) > 0 and -Mq[0] > mq[0]:
        from_M = heapq.heappop(Mq)
        from_m = heapq.heappop(mq)
        heapq.heappush(mq, -from_M)
        heapq.heappush(Mq, -from_m)
    print(-Mq[0])