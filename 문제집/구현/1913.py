from sys import stdin
input = stdin.readline
n = int(input().rstrip())
find = int(input().rstrip())
arr = [[0] * n for _ in range(n)]

num = n * n
x, y = 0, 0
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
d = 0
arr[x][y] = num
for i in range(n * n - 1):
    num -= 1
    nx, ny = x + dx[d], y + dy[d]
    turn = False
    if nx < 0 or ny < 0 or nx >= n or ny >= n:
        turn = True
    elif arr[nx][ny] != 0:
        turn = True
    if turn:
        d = (d + 1) % 4
        nx, ny = x + dx[d], y + dy[d]
    x, y = nx, ny
    arr[x][y] = num

a1 = 0
a2 = 0
for i in range(n):
    for j in range(n):
        if find == arr[i][j]:
            a1, a2 = i, j
        print(arr[i][j], end=" ")
    print()
print(a1 + 1, a2 + 1)
