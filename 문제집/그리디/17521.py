from sys import stdin
input = stdin.readline

n, w = map(int, input().rstrip().split())

arr = []
for _ in range(n):
    now = int(input().rstrip())
    arr.append(now)

if n == 1:
    print(w)
    exit(0)
c = 0
if arr[0] < arr[1]:
    c = w // arr[0]
    w -= (w // arr[0]) * arr[0]

for i in range(1, n - 1):
    before = arr[i - 1]
    now = arr[i]
    after = arr[i + 1]
    # buy
    if now < after and now <= before:
        tmp = w // now
        c += tmp
        w -= (tmp * now)
    elif now > after and now >= before:
        w += (c * now)
        c = 0
    # print(c, w)
w += (c * arr[n - 1])
print(w)
