from sys import stdin

input = stdin.readline

n = int(input().rstrip())
arr = []
the_sum = 0
for _ in range(n):
    t1, t2 = map(int, input().rstrip().split())
    arr.append((t1, t2))
    the_sum += t2
arr.sort()
the_mid = the_sum / 2

after_sum = 0
ans = 0
for i in range(n):
    after_sum += arr[i][1]
    if after_sum >= the_mid:
        ans = arr[i][0]
        break
print(ans)