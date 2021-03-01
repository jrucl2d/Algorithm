import sys

input = sys.stdin.readline

n = int(input().rstrip())
we = list(map(int, input().rstrip().split()))
m = int(input().rstrip())
box = list(map(int, input().rstrip().split()))
we.sort(reverse=True)
box.sort(reverse=True)

if box[0] > we[0]:
    print(-1)
    exit(0)

ans = 0
while True:
    if len(box) == 0:
        print(ans)
        break
    for w in we:
        for b in range(len(box)):
            if w >= box[b]:
                box.remove(box[b])
                break
    ans += 1