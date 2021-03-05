from sys import stdin
input = stdin.readline

n, m = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))
ans = 0
the_sum = 0
for i in arr:
    if the_sum + i > m:
        ans += 1
        the_sum = i
    else:
        the_sum += i
if the_sum != 0:
    ans += 1
print(ans)
