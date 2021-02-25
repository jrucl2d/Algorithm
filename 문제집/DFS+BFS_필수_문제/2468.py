from sys import stdin
INF = int(1e9)
input = stdin.readline

n = int(input().rstrip())
arr = []
tmparr = [[0] * (n) for _ in range(n)]
for i in range(n):
    tmp = list(map(int, input().rstrip().split()))
    arr.append(tmp)

for i in range(n):
    for j in range(n):
        tmparr[i][j] = arr[i][j]
ans = 0
visited = [[False] * (n + 1) for _ in range(n + 1)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def sink(height):
    global arr
    for i in range(n):
        for j in range(n):
            if arr[i][j] <= height:
                arr[i][j] = -1


def restore():
    global arr, tmparr
    for i in range(n):
        for j in range(n):
            arr[i][j] = tmparr[i][j]


def dfs(x, y):
    global arr
    stack = []
    stack.append((x, y))
    while stack:
        x, y = stack.pop()
        # 체크인
        arr[x][y] = -1

        # 갈 수 있으면 간다
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if nx < 0 or ny < 0 or nx >= n or ny >= n or arr[nx][ny] == -1:
                continue
            stack.append((nx, ny))


ans = -INF
for height in range(0, 101):
    sink(height)

    inner_ans = 0
    for i in range(n):
        for j in range(n):
            if arr[i][j] != -1:
                dfs(i, j)
                inner_ans += 1
    ans = max(inner_ans, ans)
    restore()
print(ans)
