from sys import stdin
input = stdin.readline

n, c = map(int, input().rstrip().split())
m = int(input().rstrip())
arr = []
for _ in range(m):
    x, y, z = map(int, input().rstrip().split())
    arr.append((x, y, z))

arr.sort(key=lambda x : (x[1], x[0]))

the_max = [c] * n
ans = 0

for now in arr:
    start, end, weight = now
    inner_min = int(1e9)
    for i in range(start, end):
        inner_min = min(the_max[i], inner_min)
    if inner_min < weight:
        weight = inner_min
    for i in range(start, end):
        the_max[i] -= weight
    ans += weight
    # print(the_max)
print(ans)