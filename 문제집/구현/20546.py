from sys import stdin
input = stdin.readline
money = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))

jun_money = money
sun_money = money
jun_jusik = 0
sun_jusik = 0

before_money = arr[0]
up_cnt = 0
down_cnt = 0
for now in arr:
    if jun_money >= now:
        jun_jusik += (jun_money // now)
        jun_money = jun_money % now
    if before_money < now:
        up_cnt += 1
        down_cnt = 0
        if up_cnt == 3:
            up_cnt = 2
            sun_money += (sun_jusik * now)
            sun_jusik = 0
    elif before_money > now:
        down_cnt += 1
        up_cnt = 0
        if down_cnt == 3:
            down_cnt = 2
            sun_jusik += (sun_money // now)
            sun_money = sun_money % now
    before_money = now

jun = jun_money + jun_jusik * arr[13]
sun = sun_money + sun_jusik * arr[13]
if jun > sun:
    print("BNP")
elif jun == sun:
    print("SAMESAME")
else:
    print("TIMING")