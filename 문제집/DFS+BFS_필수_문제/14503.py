from sys import stdin

BLANK = 0
WALL = 1
CLEANED = 2

input = stdin.readline

# 북 동 남 서
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
arr = []

n, m = map(int, input().rstrip().split())
px, py, d = map(int, input().rstrip().split())
for i in range(n):
    tmp = list(map(int, input().rstrip().split()))
    arr.append(tmp)

def left(dir):
    dir -= 1
    if dir == -1:
        return 3
    else:
        return dir

ans = 0
end = False
stack = []
stack.append((px, py))

# 1번
while stack:
    x, y = stack.pop()
    arr[x][y] = CLEANED
    ans += 1

    two_cnt = 0
    # 2번
    while True:
        the_left = left(d)
        nx = x + dx[the_left]
        ny = y + dy[the_left]

        if arr[nx][ny] == BLANK:
            d = the_left
            stack.append((nx, ny))
            break
        else:
            d = the_left
            two_cnt += 1
        if two_cnt == 4:
            two_cnt = 0
            back = left(left(d))
            bx = x + dx[back]
            by = y + dy[back]
            if arr[bx][by] == WALL:
                end = True
                break
            else:
                x, y = bx, by
    
    if end:
        print(ans)
        break