#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, indegree[32001];
vector<int> adj[32001]; // ���� ����Ʈ
queue<int> ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b] += 1;
	}

	// indegree�� 0�� ���� ã�Ƽ�
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			ans.push(i);
		}
	}

	while (!ans.empty()) {
		int now = ans.front(); ans.pop();
		cout << now << " ";
		for (int i = 0; i < adj[now].size(); i++) {
			int nextIndex = adj[now][i];
			indegree[nextIndex] -= 1;
			if (indegree[nextIndex] == 0) {
				ans.push(nextIndex);
			}
		}
	}
	return 0;
}