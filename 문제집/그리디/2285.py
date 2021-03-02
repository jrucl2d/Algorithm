from sys import stdin

input = stdin.readline

n = int(input().rstrip())
arr = []
the_sum = 0
for i in range(n):
    a, b = map(int, input().rstrip().split())
    the_sum += b
    arr.append((a, b))

arr.sort()
the_mid = the_sum / 2

after_sum = 0
for i in range(n):
    after_sum += arr[i][1]
    if after_sum > the_mid:
        print(arr[i][0])
        break
