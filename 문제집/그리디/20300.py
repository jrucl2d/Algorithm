from sys import stdin

input = stdin.readline

n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))
arr.sort()
if n % 2 == 0:
    ans = -1
    for i in range(n // 2):
        ans = max(ans, arr[i] + arr[n - i - 1])
else:
    ans = arr[n - 1]
    for i in range((n - 1) // 2):
        ans = max(ans, arr[i] + arr[n - i - 2])

print(ans)