from bisect import bisect_right
from sys import stdin
input = stdin.readline
n, k = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))
tmp = arr[:]
for i in range(1, n):
    arr[i] = arr[i - 1] + arr[i]
the_last = arr[n - 1]
for i in range(n - 1, -1, -1):
    the_last += tmp[i]
    arr.append(the_last)

ans = bisect_right(arr, k)
if ans >= n:
    print(2 * n - ans)
else:
    print(ans + 1)
