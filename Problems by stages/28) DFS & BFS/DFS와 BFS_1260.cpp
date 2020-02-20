#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000 + 1

int n, m, v;
int arr[MAX][MAX];
bool visited[MAX];

void dfs(int start) {
	visited[start] = true; // dfs�� ������ �湮�� ���̴�.
	cout << start << " "; // �湮�� ��� ���

	for (int i = 1; i <= n; i++) {
		// �̹� �湮�� ��(visited[i]=true)�̰ų� ������ ���� ���(arr[start]=1)�� �ǳʶ�
		if (visited[i] == true || arr[start][i] == 0)
			continue;
		dfs(i);
	}
}

void bfs(int start) { // ť�� �̿�
	queue<int>q;
	q.push(start); // ���� ������ ť�� �߰�
	visited[start] = true; // �湮�ߴٰ� ǥ��

	while (!q.empty()) {
		start = q.front(); // ť�� �� ���� ������
		cout << start << " ";
		q.pop();
		for (int i = 1; i <= n; i++) { // �ش� ������ ������ ��� ������ ť�� �߰��ϰ� bfs �����
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
		arr[a][b] = 1; arr[b][a] = 1; // ���� �ľ�
	}
	dfs(v);
	cout << "\n";
	for (int i = 0; i < MAX; i++)
		visited[i] = false;
	bfs(v);
}