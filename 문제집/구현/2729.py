from sys import stdin
input = stdin.readline
t = int(input().rstrip())

for _ in range(t):
    ta, tb = input().rstrip().split()
    a, b = '', ''
    for i in range(len(ta) - 1, -1, -1):
        a += ta[i]
    for i in range(len(tb) - 1, -1, -1):
        b += tb[i]
    na, nb = len(a), len(b)
    if na < nb:
        na, nb = nb, na
        a, b = b, a
    for i in range(na - nb):
        b += '0'
    buffer = False
    ans = ''
    for i in range(na):
        if a[i] == '0' and b[i] == '0':
            if buffer:
                ans += '1'
                buffer = False
            else:
                ans += '0'
        elif (a[i] == '0' and b[i] == '1') or (a[i] == '1' and b[i] == '0'):
            if buffer:
                ans += '0'
                buffer = True
            else:
                ans += '1'
        elif a[i] == '1' and b[i] == '1':
            if buffer:
                ans += '1'
                buffer = True
            else:
                ans += '0'
                buffer = True
    if buffer:
        ans += '1'
    first = True
    ret = ''
    for i in range(len(ans) - 1, -1, -1):
        if first and ans[i] == '0':
            continue
        if first and ans[i] != '0':
            first = False
        ret += ans[i]
    if ret == '':
        print(0)
    else:
        print(ret)
