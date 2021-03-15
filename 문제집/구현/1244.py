from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = [0]
tmp = list(map(int, input().rstrip().split()))
arr.extend(tmp)

jj = int(input().rstrip())
for _ in range(jj):
    a, b = map(int, input().rstrip().split())
    if a == 1:
        for i in range(b, n + 1, b):
            arr[i] = (arr[i] + 1) % 2
    else:
        arr[b] = (arr[b] + 1) % 2
        for i in range(1, 1011):
            if b + i >= n + 1 or b - i < 1:
                break
            if arr[b + i] != arr[b - i]:
                break
            if arr[b + i] == arr[b - i]:
                arr[b + i] = (arr[b + i] + 1) % 2
                arr[b - i] = arr[b + i]

cnt = 0
for i in range(1, n + 1):
    print(arr[i], end=" ")
    cnt += 1
    if cnt == 20:
        cnt = 0
        print()
