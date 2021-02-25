from sys import stdin
from collections import deque
input = stdin.readline

n, k = map(int, input().rstrip().split())

# bfs
q = deque()
q.append((0, n))
dp = [-1] * (100010)
dp[n] = 0
while q:
    cost, now = q.popleft()
    dp[now] = cost
    # print(now)
    if now == k:
        print(cost)
        break
    if now <= (k + 1) // 2 and dp[now * 2] == -1:
        q.append((cost + 1, now * 2))
    if now - 1 >= 0 and dp[now - 1] == -1:
        q.append((cost + 1, now - 1))
    if now + 1 <= k and dp[now + 1] == -1:
        q.append((cost + 1, now + 1))
