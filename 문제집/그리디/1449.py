from sys import stdin
input = stdin.readline
n, l = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))
arr.sort()
ans = 1
the_len = arr[0] + l - 1
for i in arr:
    if i <= the_len:
        continue
    else:
        ans += 1
        the_len = i + l - 1
print(ans)
