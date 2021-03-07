from sys import stdin
input = stdin.readline
n, m = map(int, input().rstrip().split())
arr = []
for _ in range(n):
    tmp = input().rstrip()
    itmp = []
    for i in tmp:
        itmp.append(int(i))
    arr.append(itmp)

ans = 0


def flip(x, y):
    global ans
    ans += 1
    for i in range(0, x + 1):
        for j in range(0, y + 1):
            if arr[i][j] == 0:
                arr[i][j] = 1
            else:
                arr[i][j] = 0


for i in range(n - 1, -1, -1):
    for j in range(m - 1, -1, -1):
        if arr[i][j] == 1:
            flip(i, j)
print(ans)
