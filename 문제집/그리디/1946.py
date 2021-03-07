from sys import stdin
input = stdin.readline
t = int(input().rstrip())
for ___ in range(t):
    n = int(input().rstrip())
    arr = []
    for _ in range(n):
        a, b = map(int, input().rstrip().split())
        arr.append((a, b))
    arr.sort()
    ans = 1
    now = arr[0][1]
    for i in range(1, n):
        if now > arr[i][1]:
            ans += 1
            now = arr[i][1]
    print(ans)
