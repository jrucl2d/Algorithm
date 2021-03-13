from sys import stdin
input = stdin.readline
t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    arr = list(map(int, input().rstrip().split()))
    print(min(arr), max(arr))