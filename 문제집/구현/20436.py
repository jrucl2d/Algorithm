from sys import stdin
input = stdin.readline
pos = [(1, 0), (2, 4), (2, 2), (1, 2), (0, 2), (1, 3), (1, 4), (1, 5), (0, 7), (1, 6), (1, 7), (1, 8), (2, 6),
       (2, 5), (0, 8), (0, 9), (0, 0), (0, 3), (1, 1), (0, 4), (0, 6), (2, 3), (0, 1), (2, 1), (0, 5), (2, 0)]
lefts = ['q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v']
sa, sb = map(str, input().rstrip().split())
word = input().rstrip()


def num(w):
    return ord(w) - ord('a')


lx, ly = pos[num(sa)]
rx, ry = pos[num(sb)]

ans = 0
for w in word:
    if w in lefts:
        w = num(w)
        x, y = abs(pos[w][0] - lx), abs(pos[w][1] - ly)
        ans += (x + y + 1)
        lx, ly = pos[w]
    else:
        w = num(w)
        x, y = abs(pos[w][0] - rx), abs(pos[w][1] - ry)
        ans += (x + y + 1)
        rx, ry = pos[w]
print(ans)
