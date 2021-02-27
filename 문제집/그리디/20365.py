from sys import stdin

input = stdin.readline

n = int(input().rstrip())
s = input().rstrip()

tmp = s[0]
blue = 1 if s[0] == 'B' else 0
red = 0 if s[0] == 'B' else 1

for i in range(1, n):
    if s[i] != tmp:
        if s[i] == 'B':
            blue += 1
        else:
            red += 1
        tmp = s[i]

if blue == red:
    print(blue + 1)
else:
    print(max(blue, red))