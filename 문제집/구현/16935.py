from sys import stdin
input = stdin.readline
n, m, r = map(int, input().rstrip().split())
arr = []


def func(op):
    global arr, n, m
    if op == 1:
        for j in range(m):
            for i in range(n // 2):
                arr[i][j], arr[n - i - 1][j] = arr[n - i - 1][j], arr[i][j]
    elif op == 2:
        for i in range(n):
            for j in range(m // 2):
                arr[i][j], arr[i][m - j - 1] = arr[i][m - j - 1], arr[i][j]
    elif op == 3:
        tmp = []
        for j in range(m):
            inner = []
            for i in range(n - 1, -1, -1):
                inner.append(arr[i][j])
            tmp.append(inner)
        arr = tmp
    elif op == 4:
        tmp = []
        for j in range(m - 1, -1, -1):
            inner = []
            for i in range(n):
                inner.append(arr[i][j])
            tmp.append(inner)
        arr = tmp
    elif op == 5:
        tmp = [[0] * m for _ in range(n)]
        nn, mm = n // 2, m // 2
        for i in range(nn):
            for j in range(mm):
                tmp[i][j + mm] = arr[i][j]
        for i in range(nn):
            for j in range(mm, m):
                tmp[i + nn][j] = arr[i][j]
        for i in range(nn, n):
            for j in range(mm, m):
                tmp[i][j - mm] = arr[i][j]
        for i in range(nn, n):
            for j in range(mm):
                tmp[i - nn][j] = arr[i][j]
        arr = tmp
    elif op == 6:
        tmp = [[0] * m for _ in range(n)]
        nn, mm = n // 2, m // 2
        for i in range(nn):
            for j in range(mm):
                tmp[i + nn][j] = arr[i][j]
        for i in range(nn):
            for j in range(mm, m):
                tmp[i][j - mm] = arr[i][j]
        for i in range(nn, n):
            for j in range(mm, m):
                tmp[i - nn][j] = arr[i][j]
        for i in range(nn, n):
            for j in range(mm):
                tmp[i][j + mm] = arr[i][j]
        arr = tmp
    n, m = len(arr), len(arr[0])


for _ in range(n):
    tmp = list(map(int, input().rstrip().split()))
    arr.append(tmp)
r = list(map(int, input().rstrip().split()))
for op in r:
    func(op)

for i in arr:
    for j in i:
        print(j, end=" ")
    print()
