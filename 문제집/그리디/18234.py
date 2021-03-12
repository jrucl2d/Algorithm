from sys import stdin
input = stdin.readline
n, t = map(int, input().rstrip().split())
arr = []
for _ in range(n):
    a, b = map(int, input().rstrip().split())
    arr.append((a, b))
arr.sort(key=lambda x: x[1])
ans = 0
index = t - n
for start, up in arr:
    ans += (index * up + start)
    index += 1
print(ans)
