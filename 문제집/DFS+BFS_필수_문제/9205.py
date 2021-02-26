from sys import stdin
from collections import deque
input = stdin.readline

t = int(input().rstrip())
place = []
adj = []

while t > 0:
    # init 
    t -= 1
    place = []
    adj = []

    n = int(input().rstrip())
    adj = [[] for _ in range(n + 2)]
    a, b = map(int, input().rstrip().split())
    place.append((a, b))
    for _ in range(n):
        a, b = map(int, input().rstrip().split())
        place.append((a, b))
    a, b = map(int, input().rstrip().split())
    place.append((a, b))

    for i in range(n + 1):
        for j in range(i + 1, n + 2):
            if abs(place[i][1] - place[j][1]) + abs(place[i][0] - place[j][0]) <= 1000:
                adj[i].append(j)
                adj[j].append(i)
    
    # bfs
    q = deque()
    q.append(0)
    visited = [False] * (n + 2)
    visited[0] = True
    while q:
        now = q.popleft()

        for n_pos in adj[now]:
            if not visited[n_pos]:
                visited[n_pos] = True
                q.append(n_pos)
    
    if visited[n + 1]:
        print("happy")
    else:
        print("sad")