from sys import stdin
input = stdin.readline
n = int(input().rstrip())

tmp = list(map(int, input().rstrip().split()))
grow = list(map(int, input().rstrip().split()))

arr = []
for i in range(len(tmp)):
    arr.append((grow[i], tmp[i]))
ans = 0
arr.sort()
index = 0
for gr, he in arr:
    ans += (gr * index + he)
    index += 1
print(ans)
