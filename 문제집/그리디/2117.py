from sys import stdin

input = stdin.readline

n = int(input().rstrip())
arr = []
for _ in range(n):
    tmp = int(input().rstrip())
    arr.append(tmp)

arr.sort()
dp = [0] * n
for i in range(n):
    dp[i] = arr[i] * (n - i)
print(max(dp))