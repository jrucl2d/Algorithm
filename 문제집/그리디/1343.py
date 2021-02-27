from sys import stdin

input = stdin.readline

s = input().rstrip()

tmp = 0
ans = ''
nope = False

def make_board(cnt):
    global nope
    if cnt % 2 != 0:
        nope = True
        return ''
    inner_ans = ""
    four_cnt = cnt // 4
    for i in range(four_cnt):
        inner_ans += 'AAAA'
    two_cnt = cnt - four_cnt * 4
    two_cnt = two_cnt // 2
    for i in range(two_cnt):
        inner_ans += 'BB'
    return inner_ans


for i in range(len(s) + 1):
    if nope:
        break
    if i == len(s):
        if tmp != 0:
            ans += make_board(tmp)
    elif s[i] == '.':
        if tmp != 0:
            ans += make_board(tmp)
        tmp = 0
        ans += '.'
    else:
        tmp += 1

if nope:
    print(-1)
else:
    print(ans)