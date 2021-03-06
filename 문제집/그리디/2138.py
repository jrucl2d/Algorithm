from sys import stdin
input = stdin.readline
n = int(input().rstrip())
before = []
after = []
tmp = input().rstrip()
for i in tmp:
    before.append(int(i))
tmp = input().rstrip()
for i in tmp:
    after.append(int(i))

ans = 0
def rev(index):
    global ans
    ans += 1
    for i in range(index - 1, index + 2):
        if i < 0 or i >= n:
            continue
        if before[i] == 1:
            before[i] = 0
        else:
            before[i] = 1

def check_done():
    for i in range(n):
        if before[i] != after[i]:
            return False
    return True

def copying():
    tmp = []
    for i in range(n):
        tmp.append(before[i])
    return tmp

def copying_back(tmp):
    global before
    for i in range(n):
        before[i] = tmp[i]

the_tmp = copying()
ans = 0
INF = int(1e9)
before_ans = INF
# 첫 번째를 누를 경우
rev(0)
for i in range(1, n):
    if before[i - 1] != after[i - 1]:
        rev(i)
if check_done():
    before_ans = ans
ans = 0
copying_back(the_tmp)
# 첫 번째를 누르지 않을 경우
for i in range(1, n):
    if before[i - 1] != after[i - 1]:
        rev(i)
if check_done():
    print(min(before_ans, ans))
elif not check_done():
    if before_ans == INF:
        print(-1)
    else:
        print(before_ans)