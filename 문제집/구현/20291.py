from sys import stdin
input = stdin.readline

n = int(input().rstrip())
the_map = {}
for _ in range(n):
    now = input().rstrip()
    now = now.split(".")
    if now[1] in the_map.keys():
        the_map[now[1]] += 1
    else:
        the_map[now[1]] = 1
ans_arr = list(the_map.keys())
ans_arr.sort()
for i in ans_arr:
    print(i, the_map[i])
