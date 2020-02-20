#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100 + 1

int n, m, v;
int arr[MAX][MAX];
bool visited[MAX];
int cnt = 0;

void dfs(int start) {
	visited[start] = true; // dfs�� ������ �湮�� ���̴�.
	cnt++;

	for (int i = 1; i <= n; i++) {
		// �̹� �湮�� ��(visited[i]=true)�̰ų� ������ ���� ���(arr[start]=1)�� �ǳʶ�
		if (visited[i] == true || arr[start][i] == 0)
			continue;
		dfs(i);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		arr[a][b] = 1; arr[b][a] = 1;
	}
	dfs(1); // 1�� ��ǻ�Ͱ� ���̷����� �ɷ��� ��� ����� ��ǻ�� �� - 1(1�� ��ǻ�� �ڽ�)
	cout << cnt - 1;
}