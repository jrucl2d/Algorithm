from sys import stdin
input = stdin.readline
arr = []
location = [[0, 0]] * 26
for i in range(5):
    tmp = list(map(int, input().rstrip().split()))
    arr.append(tmp)
    for j in range(5):
        location[arr[i][j]] = [i, j]


def is_bingo():
    the_count = 0
    global arr
    for i in range(5):
        cnt = 0
        for j in range(5):
            if arr[i][j] == -1:
                cnt += 1
        if cnt == 5:
            the_count += 1
    for i in range(5):
        cnt = 0
        for j in range(5):
            if arr[j][i] == -1:
                cnt += 1
        if cnt == 5:
            the_count += 1
    cnt = 0
    for i in range(5):
        if arr[i][i] == -1:
            cnt += 1
    if cnt == 5:
        the_count += 1
    cnt = 0
    for i in range(5):
        if arr[4 - i][i] == -1:
            cnt += 1
    if cnt == 5:
        the_count += 1

    # print()
    # for i in arr:
    #     print(i)
    # print(the_count)
    return the_count


ans = -1
count = 0
for i in range(5):
    tmp = list(map(int, input().rstrip().split()))
    if ans != -1:
        continue
    for j in range(5):
        count += 1
        x, y = location[tmp[j]]
        arr[x][y] = -1
        if is_bingo() >= 3:
            ans = count
            break
print(ans)
