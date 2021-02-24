from sys import stdin

input = stdin.readline

n = int(input().rstrip())
m = int(input().rstrip())
arr = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().rstrip().split())
    arr[a].append(b)
    arr[b].append(a)

visited = [False] * (n + 1)
def dfs(index):
    # 체크인
    visited[index] = True
    # 갈 수 있으면 간다
    for i in arr[index]:
        if not visited[i]:
            dfs(i)

dfs(1)
ans = 0
for i in range(2, n + 1):
    if visited[i]:
        ans += 1

print(ans)
