from sys import stdin
input = stdin.readline
n = int(input().rstrip())
mine = []
for _ in range(n):
    tmp = input().rstrip()
    mine.append(tmp)
arr = []
is_mine_touch = False
for _ in range(n):
    tmp = input().rstrip()
    for i in range(n):
        if tmp[i] == 'x' and mine[_][i] == '*':
            is_mine_touch = True
    arr.append(tmp)

ans = [[0] * n for _ in range(n)]
dx = [-1, 0, 1, 0, -1, -1, 1, 1]
dy = [0, -1, 0, 1, -1, 1, -1, 1]
for i in range(n):
    for j in range(n):
        if arr[i][j] == '.':
            ans[i][j] = -1
            continue
        mine_cnt = 0
        for d in range(8):
            nx = i + dx[d]
            ny = j + dy[d]
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue
            if mine[nx][ny] == '*':
                mine_cnt += 1
        ans[i][j] = mine_cnt

for i in range(n):
    for j in range(n):
        if is_mine_touch and mine[i][j] == '*':
            print('*', end="")
            continue
        if ans[i][j] == -1:
            print('.', end="")
            continue
        print(ans[i][j], end="")
    print()
