from sys import stdin
input = stdin.readline
while True:
    n, m = map(int, input().rstrip().split())
    if n == 0 and m == 0:
        break
    arr = [[0, i] for i in range(10001)]
    for _ in range(n):
        now = list(map(int, input().rstrip().split()))
        for i in now:
            arr[i][0] += 1
    arr.sort(reverse=True)
    the_max = arr[0][0]
    second = False
    ans = []
    for cnt, num in arr:
        if cnt != the_max and not second:
            second = True
            the_max = cnt
        if second and cnt != the_max:
            break
        if second:
            ans.append(num)
    ans.sort()
    for i in ans:
        print(i, end=" ")
    print()
