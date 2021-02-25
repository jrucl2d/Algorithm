from collections import deque
from sys import stdin
input = stdin.readline

arr = []
m, n, h = map(int, input().rstrip().split())
visited = [[[False] * m for _ in range(n)] for __ in range(h)]

q = deque()

for k in range(h):
    inner_tmp = []
    for i in range(n):
        tmp = list(map(int, input().rstrip().split()))
        inner_tmp.append(tmp)
        for j in range(m):
            if tmp[j] == -1 or tmp[j] == 1:
                visited[k][i][j] = True
            if tmp[j] == 1:
                q.append((0, k, i, j))
    arr.append(inner_tmp)

dx = [-1, 0, 1, 0, 0, 0]
dy = [0, -1, 0, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]

# bfs
ans = 0
while q:
    cnt, z, x, y = q.popleft()
    if cnt != ans:
        ans += 1
    for d in range(6):
        nx = x + dx[d]
        ny = y + dy[d]
        nz = z + dz[d]

        if nx < 0 or ny < 0 or nz < 0 or nx >= n or ny >= m or nz >= h:
            continue
        if visited[nz][nx][ny]:
            continue
        visited[nz][nx][ny] = True
        q.append((cnt + 1, nz, nx, ny))

done = True
for k in visited:
    for i in k:
        for j in i:
            if not j:
                done = False
if done:
    print(ans)
else:
    print(-1)
