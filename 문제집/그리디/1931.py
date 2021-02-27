from sys import stdin

input = stdin.readline

n = int(input().rstrip())
arr = []
for i in range(n):
    a, b = map(int, input().rstrip().split())
    arr.append((a, b))
arr.sort(key=lambda x : (x[1], x[0]))

the_end = arr[0][1]
ans = 1
for i in range(1, n):
    if arr[i][0] >= the_end:
        the_end = arr[i][1]
        ans += 1
print(ans)
