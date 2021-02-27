from sys import stdin

input = stdin.readline

n = int(input().rstrip())
arr = []
for _ in range(n):
    tmp = int(input().rstrip())
    arr.append(tmp)

arr.sort(reverse=True)

ans = 0
i = 0
while True:
    if i + 3 >= n:
        if i + 3 == n:
            ans += (arr[i] + arr[i + 1])
        else:
            for j in range(i, n):
                ans += arr[j]
        break
    else:
       ans += (arr[i] + arr[i + 1]) 
    i += 3

print(ans)