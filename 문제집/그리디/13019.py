from sys import stdin
input = stdin.readline
a = input().rstrip()
b = input().rstrip()
a_cnt = [0] * 26
b_cnt = [0] * 26
for i in range(len(a)):
    a_cnt[ord(a[i]) - ord('A')] += 1
    b_cnt[ord(b[i]) - ord('A')] += 1
for i in range(26):
    if a_cnt[i] != b_cnt[i]:
        print(-1)
        exit(0)

# 뒤에서부터 움직이지 않아도 되는 문자 개수를 센다.
ans = 0
b_index = len(b) - 1
for i in range(len(a) - 1, -1, -1):
    if a[i] == b[b_index]:
        b_index -= 1
        ans += 1
    if b_index == -1:
        break
print(len(b) - ans)
