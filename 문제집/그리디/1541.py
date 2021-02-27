from sys import stdin

input = stdin.readline

s = input().rstrip()

plused = []
minused = []

changed = False
tmp = ''
for i in s:
    if i == '+':
        if changed:
            minused.append(int(tmp))
        else:
            plused.append(int(tmp))
        tmp = ''
    elif i == '-':
        if not changed:
            plused.append(int(tmp))
            changed = True
        else:
            minused.append(int(tmp))
        tmp = ''
    else:
        tmp += i
if changed:
    minused.append(int(tmp))
else:
    plused.append(int(tmp))
# print(plused)
# print(minused)
print(sum(plused) - sum(minused))
