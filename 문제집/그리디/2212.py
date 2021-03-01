import sys

input = sys.stdin.readline

n = int(input().rstrip())
k = int(input().rstrip())

arr = list(map(int, input().rstrip().split()))
arr = set(arr)
arr = list(arr)
arr.sort()
chas = []
for i in range(1, len(arr)):
    chas.append(arr[i] - arr[i - 1])

# print(chas)
chas.sort()
ans = 0
for i in range(len(chas) - (k - 1)):
    ans += chas[i]

print(ans)