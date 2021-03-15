from sys import stdin
input = stdin.readline

n = int(input().rstrip())
the_num = 1 + (n - 1) * 4

arr = [[1] * the_num for _ in range(the_num)]

the_len = the_num
for now in range(1, the_num // 2 + 1):
    the_len -= 2
    for i in range(now, now + the_len):
        for j in range(now, now + the_len):
            if now % 2 == 1:
                arr[i][j] = 0
            else:
                arr[i][j] = 1

for i in range(the_num):
    for j in range(the_num):
        if arr[i][j] == 1:
            print('*', end="")
        else:
            print(" ", end="")
    print()
