from sys import stdin
from collections import deque
input = stdin.readline

n, start, dest, up, down = map(int, input().rstrip().split())

visited = [-1] * (n + 1)
visited[start] = 0

# bfs
q = deque()
q.append(start)

while q:
    now = q.popleft()

    if now + up <= n and visited[now + up] == -1:
        visited[now + up] = visited[now] + 1
        q.append(now + up)
    if now - down >= 1 and visited[now - down] == -1:
        visited[now - down] = visited[now] + 1
        q.append(now - down)

if visited[dest] == -1:
    print("use the stairs")
else:
    print(visited[dest])
