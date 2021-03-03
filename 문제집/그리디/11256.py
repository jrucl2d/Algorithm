from sys import stdin
input = stdin.readline

t = int(input().rstrip())
for _ in range(t):
    j, n = map(int, input().rstrip().split())
    arr = []
    for __ in range(n):
        a, b = map(int, input().rstrip().split())
        arr.append(a * b)
    arr.sort(reverse=True)
    ans = 0
    the_sum = 0
    for i in arr:
        the_sum += i
        ans += 1
        if the_sum >= j:
            break
    print(ans)
