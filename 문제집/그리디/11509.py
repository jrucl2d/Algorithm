from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))
ans = []
for now in arr:
    if len(ans) == 0:
        ans.append(now)
        continue
    added = False
    for j in range(len(ans)):
        if now + 1 == ans[j]:
            ans[j] = now
            added = True
            break
    if not added:
        ans.append(now)
print(len(ans))
