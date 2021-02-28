from sys import stdin

input = stdin.readline

a, b = map(int, input().rstrip().split())

ans = 0
can = False
while a <= b:
    # print(a , b)
    ans += 1
    if a == b:
        can = True
        break
    if (b - 1) % 10 == 0:
        b = b // 10
        continue
    if b % 2 == 0:
        b = b // 2
        continue
    else:
        break

if can:
    print(ans)
else:
    print(-1)