#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000 + 1

int n, m, v;
int arr[MAX][MAX];
bool visited[MAX];

void dfs(int start) {
	visited[start] = true; // dfs에 들어오면 방문한 것이다.
	cout << start << " "; // 방문한 노드 출력

	for (int i = 1; i <= n; i++) {
		// 이미 방문한 곳(visited[i]=true)이거나 간선이 없는 경우(arr[start]=1)은 건너뜀
		if (visited[i] == true || arr[start][i] == 0)
			continue;
		dfs(i);
	}
}

void bfs(int start) { // 큐를 이용
	queue<int>q;
	q.push(start); // 시작 정점을 큐에 추가
	visited[start] = true; // 방문했다고 표시

	while (!q.empty()) {
		start = q.front(); // 큐의 맨 앞을 가져옴
		cout << start << " ";
		q.pop();
		for (int i = 1; i <= n; i++) { // 해당 정점에 인접한 모든 정점을 큐에 추가하고 bfs 계속함
			if (visited[i] == true || arr[start][i] == 0)
				continue;
			q.push(i);
			visited[i] = true;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n >> m >> v;
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		arr[a][b] = 1; arr[b][a] = 1; // 간선 파악
	}
	dfs(v);
	cout << "\n";
	for (int i = 0; i < MAX; i++)
		visited[i] = false;
	bfs(v);
}