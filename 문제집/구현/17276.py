from sys import stdin
input = stdin.readline
t = int(input().rstrip())


def turn_left(arr):
    n = len(arr)
    zoo = []
    gaun = []
    boo = []
    gaha = []
    for i in range(n):
        for j in range(n):
            if i == j:
                zoo.append(arr[i][j])
            if j == n // 2:
                gaun.append(arr[i][j])
            if j == n - i - 1:
                boo.append(arr[i][j])
            if i == n // 2:
                gaha.append(arr[i][j])

    for i in range(n):
        arr[i][n // 2] = boo[i]
        arr[n - i - 1][i] = gaha[i]
        arr[n // 2][i] = zoo[i]
        arr[i][i] = gaun[i]
    return arr


def turn_right(arr):
    n = len(arr)
    zoo = []
    gaun = []
    boo = []
    gaha = []
    for i in range(n):
        for j in range(n):
            if i == j:
                zoo.append(arr[i][j])
            if j == n // 2:
                gaun.append(arr[i][j])
            if j == n - i - 1:
                boo.append(arr[i][j])
            if i == n // 2:
                gaha.append(arr[i][j])

    for i in range(n):
        arr[i][n // 2] = zoo[i]
        arr[i][n - i - 1] = gaun[i]
        arr[n // 2][n - i - 1] = boo[i]
        arr[i][i] = gaha[i]
    return arr


for _ in range(t):
    n, d = map(int, input().rstrip().split())
    arr = []
    for __ in range(n):
        tmp = list(map(int, input().rstrip().split()))
        arr.append(tmp)
    d /= 45
    d = int(d)
    while d > 0:
        arr = turn_right(arr)
        d -= 1
    while d < 0:
        arr = turn_left(arr)
        d += 1
    for i in arr:
        for j in i:
            print(j, end=" ")
        print()
