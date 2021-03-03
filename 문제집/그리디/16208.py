from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))
the_sum = sum(arr)
arr.sort(reverse=True)
ans = 0
for i in arr:
    ans += (i * (the_sum - i))
    the_sum -= i
print(ans)
