from sys import stdin
input = stdin.readline

n, l = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))
arr.sort()

for now in arr:
    if now <= l:
        l += 1
print(l)
