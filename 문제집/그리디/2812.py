import sys

input = sys.stdin.readline

n, k = map(int, input().rstrip().split())

num = input().rstrip()

the_len = n - k
ans = [int(num[0])]
a_len = 1
for i in range(1, n):
    now = num[i]
    if a_len >= the_len:
        ans[a_len - 1] = max(ans[a_len - 1], int(now))
    else:
        if ans[a_len - 1] > int(now):
            # print(a_len, the_len)
            ans.append(int(now))
            a_len += 1
        else:
            while True:
                if n - i - 1 >= the_len - a_len and len(ans) > 0 and ans[a_len - 1] < int(now):
                    ans.pop()
                    a_len -= 1
                else:
                    ans.append(int(now))
                    a_len += 1
                    break
            else:
                ans.append(int(now))
                a_len += 1
    # print(ans)
for i in ans:
    print(i, end="")