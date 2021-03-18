from sys import stdin
input = stdin.readline
INF = int(1e9)
n = input().rstrip()


def sol(num):
    n = len(num)
    ret = 0
    for i in num:
        if int(i) % 2 == 1:
            ret += 1
    the_min = INF
    the_max = -INF
    if n >= 3:
        for i in range(1, n - 1):
            for j in range(i + 1, n):
                first = num[0:i]
                second = num[i:j]
                third = num[j:]
                the_num = str(int(first) + int(second) + int(third))
                aa = sol(the_num)[1]
                bb = sol(the_num)[0]
                the_min = min(the_min, aa)
                the_max = max(the_max, bb)
    elif n == 2:
        the_num = str(int(num[0]) + int(num[1]))
        aa = sol(the_num)[1]
        bb = sol(the_num)[0]
        the_min = min(the_min, aa)
        the_max = max(the_max, bb)
    elif n == 1:
        return (ret, ret)
    the_max, the_min = the_max + ret, the_min + ret
    # print(num, "일 때", the_max, the_min)
    return (the_max, the_min)


ans = sol(n)
print(ans[1], ans[0])
