from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))
the_sum = sum(arr)
if the_sum % 3 != 0:
    print("NO")
    exit(0)

the_two = 0
for i in arr:
    the_two += (i // 2)

if the_sum // 3 <= the_two:
    print("YES")
else:
    print("NO")
