from sys import stdin
input = stdin.readline

n, m = map(int, input().rstrip().split())
a = []
b = []
for _ in range(n):
    tmp = input().rstrip()
    itmp = []
    for i in tmp:
        itmp.append(int(i))
    a.append(itmp)
for _ in range(n):
    tmp = input().rstrip()
    itmp = []
    for i in tmp:
        itmp.append(int(i))
    b.append(itmp)

ans = 0
def rev(ii, jj):
    global ans
    ans += 1
    for i in range(3):
        for j in range(3):
            ni = ii + i
            nj = jj + j
            if a[ni][nj] == 0:
                a[ni][nj] = 1
            else:
                a[ni][nj] = 0

for i in range(n - 2):
    for j in range(m - 2):
        if a[i][j] != b[i][j]:
            rev(i, j)

for i in range(n):
    for j in range(m): 
        if a[i][j] != b[i][j]:
            print(-1)
            exit(0)
print(ans)