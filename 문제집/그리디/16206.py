from sys import stdin
input = stdin.readline
n, m = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))
can_get = []
ans = 0
for now in arr:
    if now == 10:
        ans += 1
    elif now % 10 == 0:
        div_ten = now // 10
        # 맨 앞은 자르는 것 대비 얻는 이득의 비율 앞 번 짜르는 걸로 뒤 개를 얻을 수 있음
        can_get.append(((div_ten / (div_ten - 1)), div_ten - 1, (div_ten)))
    else:
        div_ten = now // 10
        can_get.append((1, div_ten, div_ten))
can_get.sort(reverse=True)
# print(can_get)
for (percent, div, get) in can_get:
    if m == 0:
        break
    if m - div >= 0:
        ans += get
        m -= div
    elif m <= get:
        ans += m
        m = 0
print(ans)
