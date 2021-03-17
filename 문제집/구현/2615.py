from sys import stdin
input = stdin.readline
arr = []
for _ in range(19):
    tmp = list(map(int, input().rstrip().split()))
    arr.append(tmp)

# |
for i in range(19):
    for j in range(15):
        if arr[i][j] == 0:
            continue
        cnt = 0
        num = arr[i][j]
        for c in range(5):
            if num == arr[i][j + c]:
                cnt += 1
        if cnt == 5 and (j == 14 or (j < 14 and arr[i][j + 5] != num)) and (j == 0 or (j > 0 and arr[i][j - 1] != num)):
            print(num)
            print(i + 1, j + 1)
            exit(0)
# -
for i in range(15):
    for j in range(19):
        if arr[i][j] == 0:
            continue
        cnt = 0
        num = arr[i][j]
        for c in range(5):
            if num == arr[i + c][j]:
                cnt += 1
        if cnt == 5 and (i == 14 or (i < 14 and arr[i + 5][j] != num)) and (i == 0 or (i > 0 and arr[i - 1][j] != num)):
            print(num)
            print(i + 1, j + 1)
            exit(0)
# /
for i in range(4, 19):
    for j in range(15):
        if arr[i][j] == 0:
            continue
        cnt = 0
        num = arr[i][j]
        for c in range(5):
            if num == arr[i - c][j + c]:
                cnt += 1
        if cnt == 5 and (i == 4 or j == 14 or (i > 4 and j < 14 and arr[i - 5][j + 5] != num)) and (i == 18 or j == 0 or (i < 18 and j > 0 and arr[i + 1][j - 1] != num)):
            print(num)
            print(i + 1, j + 1)
            exit(0)
# \
for i in range(15):
    for j in range(15):
        if arr[i][j] == 0:
            continue
        cnt = 0
        num = arr[i][j]
        for c in range(5):
            if num == arr[i + c][j + c]:
                cnt += 1
        if cnt == 5 and (i == 14 or j == 14 or (i < 14 and j < 14 and arr[i + 5][j + 5] != num)) and (i == 0 or j == 0 or (i > 0 and j > 0 and arr[i - 1][j - 1] != num)):
            print(num)
            print(i + 1, j + 1)
            exit(0)
print(0)
