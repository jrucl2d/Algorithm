from sys import stdin

input = stdin.readline

n, k = map(int, input().rstrip().split())
arr = []
for _ in range(n):
    tmp = int(input().rstrip())
    arr.append(tmp)

ans = 0
for i in range(n - 1, -1, -1):
    now = arr[i]
    mok = k // now
    ans += mok
    k = (k - mok * now)
print(ans)