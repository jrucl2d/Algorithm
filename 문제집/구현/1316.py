from sys import stdin
input = stdin.readline
n = int(input().rstrip())


def group(s):
    cnt = [0] * 27
    now = s[0]
    for i in s:
        index = ord(i) - ord('a')
        if i != now and cnt[index] != 0:
            return False
        cnt[index] += 1
        now = i
    return True


ans = 0
for _ in range(n):
    s = input().rstrip()
    if group(s):
        ans += 1
print(ans)
