#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m, ans;
vector<int> adj[501];
vector<int> adj2[501];
bool visited[501];
bool visited2[501];

void dfs(int index, int& cnt) {
	if (visited[index]) return;
	visited[index] = true;
	cnt += 1;
	for (int i = 0; i < adj[index].size(); i++) {
		dfs(adj[index][i], cnt);
	}
}

void dfs2(int index, int& cnt) {
	if (visited2[index]) return;
	visited2[index] = true;
	cnt += 1;
	for (int i = 0; i < adj2[index].size(); i++) {
		dfs2(adj2[index][i], cnt);
	}
}

int main() {
	cin >> n >> m;

	// 그래프 구성
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b); // a->b
		adj2[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0; // 나 + 나보다 큰
		memset(visited, 0x00, sizeof(visited));
		dfs(i, cnt);

		int cnt2 = 0; // 나 + 나보다 작은
		memset(visited2, 0x00, sizeof(visited2));
		dfs2(i, cnt2);
		if (cnt + cnt2 == n + 1) {
			ans += 1;
		}
	}

	cout << ans;

	return 0;
}