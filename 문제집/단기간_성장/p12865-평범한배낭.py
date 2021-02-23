import sys
n, k = map(int, sys.stdin.readline().rstrip().split())
arr = []
for _ in range(n):
    w, v = map(int, sys.stdin.readline().rstrip().split())
    arr.append((w, v))
arr.sort()

# i번째 물건을 j 크기 가방에 넣을 때 최대 가치
dp = [[0] * (k + 1) for _ in range(n + 1)]
for i in range(0, n):
    for j in range(1, k + 1):
        if j - arr[i][0] >= 0:  # j용량 가방에 i번째 물건을 넣을 수 있다면
            # i번째 물건을 넣지 않았을 때
            first = dp[i - 1][j]
            # i번째 물건을 넣었을 때, i물건 넣기 전(i - 1, i의 무게만큼 전의 최대 가치)에 i의 가치를 더함
            second = dp[i - 1][j - arr[i][0]] + arr[i][1]
            dp[i][j] = max(first, second)
        else:  # j용량 가방에 i번째 물건을 넣을 수 없다면
            # 그냥 i-1까지의 최대 가치와 같다
            dp[i][j] = dp[i - 1][j]

print(dp[n - 1][k])
