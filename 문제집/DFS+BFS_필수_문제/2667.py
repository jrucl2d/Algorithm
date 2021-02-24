from sys import stdin

input = stdin.readline
n = int(input().rstrip())

arr = []
for _ in range(n):
    tmp = list(map(int, input().rstrip()))
    arr.append(tmp)

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

cnt = 0
def dfs(x, y):
    global cnt
    # 체크인
    arr[x][y] = 0
    cnt += 1

    # 갈 수 있으면 간다
    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]
        if nx < 0 or ny < 0 or nx >= n or ny >= n or arr[nx][ny] == 0:
            continue
        dfs(nx, ny)


ans = []
for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            cnt = 0
            dfs(i, j)
            ans.append(cnt)

ans.sort()
print(len(ans))
for i in ans:
    print(i)