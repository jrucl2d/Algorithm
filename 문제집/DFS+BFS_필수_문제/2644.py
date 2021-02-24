from sys import stdin
from collections import deque
input = stdin.readline

n = int(input().rstrip())
a, b = map(int, input().rstrip().split())
m = int(input().rstrip())

rels = [[] for _ in range(n + 1)]

for _ in range(m):  
    t1, t2 = map(int, input().rstrip().split())
    rels[t1].append(t2)
    rels[t2].append(t1)

# bfs
visited = [-1] * (n + 1)
visited[a] = 0
q = deque()
q.append(a)
while q:
    now = q.popleft()
    for i in rels[now]:
        if visited[i] == -1:
            visited[i] = visited[now] + 1
            q.append(i)

print(visited[b])