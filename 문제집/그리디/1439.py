from sys import stdin

input = stdin.readline

s = input().rstrip()

letter = s[0]

count = [1, 0]
c_index = 0
for i in range(1, len(s)):
    if s[i] != letter:
        letter = s[i]
        c_index = (c_index + 1) % 2
        count[c_index] += 1

print(min(count))
