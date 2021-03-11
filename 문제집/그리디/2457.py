from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = []
for _ in range(n):
    a, b, c, d = map(int, input().rstrip().split())
    arr.append((a * 100 + b, c * 100 + d))  # 월 * 100 + 일

arr.sort(key=lambda x: (x[0], x[1]))
# print(arr)
ans = 0
index = 0
inner_max = 0
day = 301
while True:
    if inner_max > 1130:
        break
    found = False
    for j in range(index, n):
        start, end = arr[j]
        if start > day:  # 중간에 붕 떠버림
            break
        if end > inner_max:
            inner_max = end
            index = j  # 다음엔 j부터 시작
            found = True
        # print(day, start, end, inner_max, index)
    if not found:  # 중간에 붕 뜨면 안 됨
        print(0)
        exit(0)
    else:
        ans += 1
    index += 1
    day = inner_max
print(ans)
