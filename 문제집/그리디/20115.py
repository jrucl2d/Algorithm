from sys import stdin

input = stdin.readline

n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))

arr.sort(reverse=True)

ans = arr[0]
for i in range(1, n):
    ans += (arr[i] / 2)

print(ans)