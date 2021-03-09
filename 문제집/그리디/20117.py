from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))
arr.sort()
if n % 2 == 0:
    ans = 0
    for i in range(n // 2, n):
        ans += arr[i]
    print(2 * ans)
else:
    ans = 0
    for i in range(n // 2 + 1, n):
        ans += arr[i]
    ans *= 2
    ans += arr[n // 2]
    print(ans)
