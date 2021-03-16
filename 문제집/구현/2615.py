from sys import stdin
input = stdin.readline
arr = []
for _ in range(19):
    tmp = list(map(int, input().rstrip().split()))
    arr.append(tmp)


def found(x, y, num):
    tx, ty = x, y
    cnt = 0
    # 세로
    while True:
        if x == 0:
            break
        if arr[x - 1][y] == num:
            x -= 1
        else:
            break
    while x < 19:
        if arr[x][y] == num:
            cnt += 1
        x += 1
    if cnt == 5:
        return True
    # 가로
    x, y = tx, ty
    cnt = 0
    while True:
        if y == 0:
            break
        if arr[x][y - 1] == num:
            y -= 1
        else:
            break
    while y < 19:
        if arr[x][y] == num:
            cnt += 1
        y += 1
    if cnt == 5:
        return True
    # 대각선
    x, y = tx, ty
    cnt = 0
    while True:
        if x == 0 or y == 0:
            break
        if arr[x - 1][y - 1] == num:
            x -= 1
            y -= 1
        else:
            break
    while x < 19 and y < 19:
        if arr[x][y] == num:
            cnt += 1
        x += 1
        y += 1
    if cnt == 5:
        return True
    return False


def found2(x, y, num):
    cnt = 0
    while True:
        if x == 19 or y == 0:
            break
        if arr[x + 1][y - 1] == num:
            x += 1
            y -= 1
        else:
            break
    while x >= 0 and y < 19:
        if arr[x][y] == num:
            cnt += 1
        x -= 1
        y += 1
    if cnt == 5:
        return True
    return False


ans = None
for i in range(14):
    for j in range(14):
        if arr[i][j] != 0:
            if found(i, j, arr[i][j]):
                ans = (arr[i][j], i + 1, j + 1)
                break
    if ans != None:
        break
if ans != None:
    print(ans[0])
    print(ans[1], ans[2])
    exit(0)
for i in range(18, 3, -1):
    for j in range(14):
        if arr[i][j] != 0:
            if found2(i, j, arr[i][j]):
                print(arr[i][j])
                print(i + 1, j + 1)
                exit(0)
print(0)
