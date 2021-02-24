from collections import deque
from sys import stdin
input = stdin.readline

n, m, v = map(int, input().rstrip().split())
arr = [[0] * (n + 1) for _ in range(n + 1)]

visited = [False] * (n + 1)
def dfs(now):
    # 체크 인
    visited[now] = True
    print(now, end=" ")

    # 갈 수 있으면 간다
    for i in range(1, n + 1):
        if not visited[i] and arr[now][i] == 1:
            dfs(i)


visited2 = [False] * (n + 1)
def bfs(now):
    q = deque()
    q.append(now)
    visited2[now] = True
    while q:
        inner_now = q.popleft()
        print(inner_now, end=" ")
        for i in range(1, n + 1):
            if arr[inner_now][i] == 1 and not visited2[i]:
                visited2[i] = True
                q.append(i)


for _ in range(m):
    t1, t2 = map(int, input().rstrip().split())
    arr[t1][t2] = 1
    arr[t2][t1] = 1

dfs(v)
print()
bfs(v)