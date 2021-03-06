from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = []
for i in range(n):
    a, b = map(int, input().rstrip().split())
    arr.append((a, b))

# 중앙값 찾기
arr.sort()
x = 0
if n % 2 == 1:
    x = arr[n // 2][0]
else:
    x = (arr[n // 2][0] + arr[n // 2 - 1][0]) // 2

arr.sort(key=lambda x : x[1])
y = 0
if n % 2 == 1:
    y = arr[n // 2][1]
else:
    y = (arr[n // 2][1] + arr[n // 2 - 1][1]) // 2

ans = 0
for i in range(n):
    ans += (abs(arr[i][0] - x) + abs(arr[i][1] - y))
print(ans)