from sys import stdin
input = stdin.readline
s = input().rstrip()
tag = False
ans = []
tmp = ''


def rev(s):
    a = []
    for i in range(len(s) - 1, -1, -1):
        a.append(s[i])
    return ''.join(a)


for i in s:
    if i == '>':
        tag = False
        ans.append(i)
        continue
    elif i == '<':
        ans.append(rev(tmp))
        tmp = ''
        tag = True
        ans.append(i)
        continue
    if tag:
        ans.append(i)
    else:
        if i != ' ' and i != '<':
            tmp += i
        else:
            ans.append(rev(tmp))
            ans.append(' ')
            tmp = ''
ans.append(rev(tmp))

for i in ans:
    print(i, end="")
