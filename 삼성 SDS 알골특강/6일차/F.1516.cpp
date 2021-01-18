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
			adj[tmp].push_back(i); // tmp�� �������� i�� ���� �� �ִ�.
			indegree[i] += 1;
		}
	}

	// ��������

	// 1. �������� 0�� ��� ť�� �ֱ�
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		// ���� ��尡 �����Ϸ��� ������ �������� �ϴ� �ǹ� �� ���� ū �ð��� ������ �Ѵ�.
		
		// �̹� theMax�� ������ �͵��� ������ ó���� �� �Ǿ��ִ�.(���� ū ���� ����ִ�.)
		ans[now] = theMax[now] + b_time[now]; // ������ ���� ū �� + ���� �ǹ� ���� �� �ɸ��� �ð�
		
		for (int i = 0; i < adj[now].size(); i++) {
			int nextIndex = adj[now][i];
			indegree[nextIndex] -= 1; // �������� ���ֱ�
			if (theMax[nextIndex] < ans[now]) { // ���� ����� �ð��� �ּ��� ���� �ɸ��� �ð� �̻�
				theMax[nextIndex] = ans[now];
			}
			if (indegree[nextIndex] == 0) { // ���������� 0�̸� ť�� �ֱ�
				q.push(nextIndex);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}