#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, b_time[510], ans[510], indegree[510], theMax[510];

vector<int> adj[510];
queue<int> q;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b_time[i];
		while (true) {		
			int tmp;
			cin >> tmp;
			if (tmp == -1) break;
			adj[tmp].push_back(i); // tmp가 지어져야 i를 지을 수 있다.
			indegree[i] += 1;
		}
	}

	// 위상정렬

	// 1. 진입차수 0인 노드 큐에 넣기
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		// 현재 노드가 시작하려면 이전에 지어져야 하는 건물 중 가장 큰 시간이 끝나야 한다.
		
		// 이미 theMax에 이전의 것들은 무조건 처리가 잘 되어있다.(가장 큰 값이 들어있다.)
		ans[now] = theMax[now] + b_time[now]; // 이전의 가장 큰 값 + 현재 건물 짓는 데 걸리는 시간
		
		for (int i = 0; i < adj[now].size(); i++) {
			int nextIndex = adj[now][i];
			indegree[nextIndex] -= 1; // 진입차수 빼주기
			if (theMax[nextIndex] < ans[now]) { // 다음 노드의 시간은 최소한 지금 걸리는 시간 이상
				theMax[nextIndex] = ans[now];
			}
			if (indegree[nextIndex] == 0) { // 진입차수가 0이면 큐에 넣기
				q.push(nextIndex);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}