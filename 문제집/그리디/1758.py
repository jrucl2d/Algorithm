from sys import stdin

input = stdin.readline

n = int(input().rstrip())
arr = []
for i in range(n):
    tmp = int(input().rstrip())
    arr.append(tmp)

arr.sort(reverse=True)
ans = 0
for i in range(n):
    inner_ans = arr[i] - i
    if inner_ans <= 0:
        ans += 0
    else:
        ans += inner_ans

print(ans)