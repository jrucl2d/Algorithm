from sys import stdin
input = stdin.readline
n, m, r = map(int, input().rstrip().split())
arr = [[0] * (m + 2) for _ in range(n + 2)]
for i in range(1, n + 1):
    tmp = list(map(int, input().rstrip().split()))
    for j in range(1, m + 1):
        arr[i][j] = tmp[j - 1]


def spin():
    tr = (m + 1) // 2
    tn, tm = n, m
    for s in range(1, 1 + tr):
        if tn <= 0 or tm <= 0:
            break
        last_one = arr[tn + s - 1][s]
        for i in range(tn + s - 1, s, -1):
            arr[i][s] = arr[i - 1][s]
        arr[s][s] = arr[s][s + 1]

        tmp_last_one = arr[tn + s - 1][tm + s - 1]
        for i in range(tm + s - 1, s, -1):
            arr[tn + s - 1][i] = arr[tn + s - 1][i - 1]
        arr[tn + s - 1][s + 1] = last_one
        last_one = tmp_last_one

        tmp_last_one = arr[s][tm + s - 1]
        for i in range(s, tn + s - 1):
            arr[i][tm + s - 1] = arr[i + 1][tm + s - 1]
        arr[tn + s - 2][tm + s - 1] = last_one
        last_one = tmp_last_one

        for i in range(s, tm + s - 1):
            arr[s][i] = arr[s][i + 1]
        arr[s][tm + s - 2] = last_one
        tn -= 2
        tm -= 2


for _ in range(r):
    spin()

for i in range(1, n + 1):
    for j in range(1, m + 1):
        print(arr[i][j], end=" ")
    print()
