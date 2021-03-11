from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))
m = int(input().rstrip())


def int_to_new(s, a):
    s = str(s)
    tmp = []
    for i in s:
        tmp.append(i)
    tmp.append(str(a))
    tmp.sort(reverse=True)
    return int(''.join(tmp))


dp = [-1] * (m + 1)
the_start = min(arr)
for money in range(the_start, m + 1):
    for i in range(n):
        the_before = money - arr[i]
        if the_before < 0:
            continue
        if dp[the_before] == -1:
            dp[money] = max(dp[money], i)
            continue
        before_str = int_to_new(dp[the_before], i)
        dp[money] = max(dp[money], before_str)
    # print(dp)
print(dp[m])
