from sys import stdin
input = stdin.readline
n, m = map(int, input().rstrip().split())
arr = []
tmps = [[0, False] for _ in range(m)]
the_lens = [int(1e9)] * m
for _ in range(n):
    now = list(input().rstrip())
    arr.append(now)
    for i in range(m):
        if now[i] == 'X':
            tmps[i][0] = 0
            tmps[i][1] = True
        elif tmps[i][1] and now[i] == '#':
            tmps[i][1] = False
            the_lens[i] = min(the_lens[i], tmps[i][0])
        elif tmps[i][1] and now[i] == '.':
            tmps[i][0] += 1

go = min(the_lens)
for i in range(n):
    for j in range(m):
        if arr[i][j] == '#':
            print('#', end="")
            continue
        if i - go >= 0:
            if arr[i - go][j] == 'X':
                print('X', end="")
            else:
                print('.', end="")
        else:
            print('.', end="")
    print()
