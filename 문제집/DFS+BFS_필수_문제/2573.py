from sys import stdin
from collections import deque
input = stdin.readline

n, m = map(int, input().rstrip().split())
arr = []
afterarr = [[0] * (m) for _ in range(n)]
q = deque()

for i in range(n):
    tmp = list(map(int, input().rstrip().split()))
    for j in range(1, m - 1):
        if tmp[j] != 0:
            q.append((0, i, j))
    arr.append(tmp)

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def find_zero_cnt(x, y, arr):
    cnt = 0
    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]
        if arr[nx][ny] == 0:
            cnt += 1
    return cnt


def find_group(visited, x, y):
    stack = [(x, y)]
    while len(stack) > 0:
        now_x, now_y = stack.pop()
        visited[now_x][now_y] = 0
        for d in range(4):
            nx = now_x + dx[d]
            ny = now_y + dy[d]
            if visited[nx][ny] != 0:
                stack.append((nx, ny))

for i in range(n):
    for j in range(m):
        afterarr[i][j] = arr[i][j]

ans = 0
found = False
while q:    
    time, x, y = q.popleft()

    if time != ans:
        ans = time
        visited = [[0] * (m) for _ in range(n)]
        for i in range(n):
            for j in range(m):
                arr[i][j] = afterarr[i][j]
                visited[i][j] = afterarr[i][j]
        the_cnt = 0
        done = False
        for i in range(1, n - 1):
            for j in range(1, m - 1):
                if visited[i][j] != 0:
                    if the_cnt == 1:
                        done = True
                        break
                    the_cnt += 1
                    find_group(visited, i, j)
            if done:
                break
        if done:
            found = True
            break

        # print(time, x, y)
        # for i in range(n):
        #     print(arr[i], end="    ")
        #     print(afterarr[i])
        # print()    

    zeros = find_zero_cnt(x, y, arr)

    afterarr[x][y] -= zeros
    if afterarr[x][y] <= 0:
        afterarr[x][y] = 0
    else:
        q.append((time + 1, x, y))
    
if found:
    print(ans)
else:
    print(0)