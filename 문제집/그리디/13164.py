from sys import stdin
input = stdin.readline

n, k = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))

minus = []
for i in range(n - 1):
    minus.append(arr[i + 1] - arr[i])
minus.sort(reverse=True)

ans = 0
for i in range(k - 1, n - 1):
    ans += minus[i]
print(ans)