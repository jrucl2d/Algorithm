from sys import stdin

input = stdin.readline

n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))

arr.sort()

for i in range(1, n):
    arr[i] = arr[i - 1] + arr[i]

print(sum(arr))