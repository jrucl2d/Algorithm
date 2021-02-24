from sys import stdin
from collections import deque
input = stdin.readline

n, m = map(int, input().rstrip().split())
arr = []

for _ in range(n):
    tmp = input().rstrip()
    arr.append(tmp)

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
INF = int(1e9)
visited = [[INF] * m for _ in range(n)]
visited[0][0] = 1
# bfs
q = deque()
q.append((0, 0))
while q:
    x, y = q.popleft()
    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]
        if nx < 0 or ny < 0 or nx >= n or ny >= m or visited[nx][ny] != INF:
            continue
        if arr[nx][ny] == '0':
            continue
        visited[nx][ny] = visited[x][y] + 1
        q.append((nx, ny))

print(visited[n - 1][m - 1])

