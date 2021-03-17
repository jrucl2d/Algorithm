from sys import stdin
input = stdin.readline
n, m = map(int, input().rstrip().split())
arr = [[0] * 21 for _ in range(n + 1)]
for _ in range(m):
    op = list(input().rstrip().split())
    if op[0] == '1':
        arr[int(op[1])][int(op[2])] = 1
    elif op[0] == '2':
        arr[int(op[1])][int(op[2])] = 0
    elif op[0] == '3':
        for i in range(20, 1, -1):
            arr[int(op[1])][i] = arr[int(op[1])][i - 1]
        arr[int(op[1])][1] = 0
    else:
        for i in range(1, 20):
            arr[int(op[1])][i] = arr[int(op[1])][i + 1]
        arr[int(op[1])][20] = 0

ans = []
for i in range(1, n + 1):
    if arr[i] in ans:
        continue
    ans.append(arr[i])
print(len(ans))
