from sys import stdin
input = stdin.readline
s = input().rstrip()
duck_queue = []
duck_sound = {
    'q': 1,
    'u': 2,
    'a': 3,
    'c': 4,
    'k': 5
}
ans = 0
for i in s:
    now = duck_sound[i]
    found = False
    for j in range(len(duck_queue)):
        if duck_queue[j] == now:
            duck_queue[j] = now + 1
            if now == 5:
                duck_queue[j] = 1
            found = True
            break
    if not found:
        duck_queue.append(now + 1)

for i in duck_queue:
    if i == 1:
        ans += 1
    else:
        print(-1)
        exit(0)
print(ans)
