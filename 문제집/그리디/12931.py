from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))


def check_zero():
    global arr
    for i in arr:
        if i != 0:
            return False
    return True


def check_odd():
    global arr
    for i in arr:
        if i % 2 != 0:
            return True
    return False


def remove_odd():
    global arr, n
    cnt = 0
    for i in range(n):
        if arr[i] % 2 != 0:
            arr[i] -= 1
            cnt += 1
    return cnt


ans = 0
while True:
    if check_zero():
        break
    if not check_odd():
        for i in range(n):
            arr[i] = arr[i] // 2
        ans += 1
        continue
    ans += remove_odd()

print(ans)
