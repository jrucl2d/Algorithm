from sys import stdin
input = stdin.readline

n = int(input().rstrip())
dist = list(map(int, input().rstrip().split()))
oil = list(map(int, input().rstrip().split()))

the_min = oil[0]
dist_sum = dist[0]
ans = 0
for i in range(1, n - 1):
    if the_min > oil[i]:
        ans += dist_sum * the_min
        dist_sum = dist[i]
        the_min = oil[i]
    else:
        dist_sum += dist[i]

ans += dist_sum * the_min
print(ans)
