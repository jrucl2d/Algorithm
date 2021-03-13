from sys import stdin
input = stdin.readline
n = int(input().rstrip())
if n % 4 == 0 and (n % 100 != 0 or n % 400 == 0):
    print(1)
else:
    print(0)