from sys import stdin
input = stdin.readline
n, m = map(int, input().rstrip().split())
if n == 1:
    print(1)
elif n == 2:
    ans = (m + 1) // 2
    if ans >= 4:
        print(4)
    else:
        print(ans)
else:
    if m <= 4:
        print(m)
    elif m <= 6:
        print(4)
    else:
        print((m - 5) + 3)
