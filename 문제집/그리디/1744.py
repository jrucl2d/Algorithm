from sys import stdin
from collections import deque
input = stdin.readline
n = int(input().rstrip())
arr = []
narr = []
for _ in range(n):
    a = int(input().rstrip())
    if a > 0:
        arr.append(a)
    else:
        narr.append(a)
arr.sort(reverse=True)
narr.sort()
arr = deque(arr)
narr = deque(narr)
ans = 0
for i in range(0, len(narr), 2):
    a = narr.popleft()
    if len(narr) == 0:
        ans += a
        break
    b = narr.popleft()
    ans += (a * b)

for i in range(0, len(arr), 2):
    a = arr.popleft()
    if len(arr) == 0:
        ans += a
        break
    b = arr.popleft()
    if b <= 1:
        ans += (a + b)
    else:
        ans += (a * b)
    # print(a, b, ans)
print(ans)
