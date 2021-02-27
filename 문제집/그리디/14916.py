from sys import stdin

input = stdin.readline

n = int(input().rstrip())

first_five = n // 5
found = False
for five_cnt in range(first_five, -1, -1):
    the_rest = n - five_cnt * 5
    if the_rest == 0:
        print(five_cnt)
        found = True
        break
    else:
        if the_rest % 2 == 0:
            print(five_cnt + the_rest // 2)
            found = True
            break
if not found:
    print(-1)
