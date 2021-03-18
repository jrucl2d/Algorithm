from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = [0] * 366
tmp = []
for _ in range(n):
    a, b = map(int, input().rstrip().split())
    tmp.append((a, b, b - a))
tmp.sort(key=lambda x: (x[0], -x[2]))
for s, e, l in tmp:
    for i in range(s, e + 1):
        arr[i] += 1

check = False
the_len = 0
the_height = 0
ans = 0
for i in arr:
    if i != 0:
        check = True
        the_len += 1
        the_height = max(the_height, i)
    elif check and i == 0:
        check = False
        ans += (the_len * the_height) 
        the_len = 0
        the_height = 0
if the_height != 0 and the_len != 0:
    ans += (the_len * the_height)
print(ans)