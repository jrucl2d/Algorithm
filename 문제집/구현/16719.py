from sys import stdin
input = stdin.readline
s = input().rstrip()
arr = []
for i in range(len(s)):
    arr.append((s[i], i))
arr.sort()
ans = []
ans.append(arr[0])
arr.remove(arr[0])
print(ans[0][0])
while len(arr) > 0:
    next_arrs = [ans[:] for _ in range(len(arr))]
    for i in range(len(arr)):
        next_arrs[i].append(arr[i])
        next_arrs[i].sort(key=lambda x: x[1])
    next_arrs.sort()
    showing = next_arrs[0]
    for i in arr:
        if i in showing:
            arr.remove(i)
            break
    for i in showing:
        print(i[0], end="")
    print()
    ans = next_arrs[0]
