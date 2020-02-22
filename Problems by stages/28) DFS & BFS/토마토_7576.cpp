#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000 + 1

int n, m;
int arr[MAX][MAX];
int visited[MAX][MAX]; // ������ ���� ����
queue<pair<int, int>>q;

// ����
int lr[4] = { -1,0,1,0 };
int ud[4] = { 0,1,0,-1 };

void bfs(int a, int b) {
	while (!q.empty()) { // ť�� ���� �ʴ� ��
		a = q.front().first;
		b = q.front().second;
		q.pop(); // ���ʰ� ������

		for (int i = 0; i < 4; i++) { // �����¿� �׹��� Ž��
			int na = a + lr[i];
			int nb = b + ud[i];
			if (1 <= na && na <= n && 1 <= nb && nb <= m) { // ���� ������
				// ���� �� �� ���̰�, �ش� ��ġ�� ���� ���� �丶�䰡 ������
				if (visited[na][nb] == -1 && arr[na][nb] == 0) {
					q.push({ na, nb }); // �ش� ��ġ ť�� �ְ�
					visited[na][nb] = visited[a][b] + 1; // ��¥ �ϳ� ����
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			visited[i][j] = -1; // �湮�ߴ��� ������ �ʱⰪ ��� -1�� ����(��¥)
			if (arr[i][j] == 1) { // �̹� �;��ִ� �丶���
				q.push({ i,j }); // ť�� �ְ�
				visited[i][j] = 0; // �湮�ߴٰ� ǥ��(ù��)
			}
		}
	}
	bfs(1, 1);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(ans, visited[i][j]); // ��¥ �߿��� �ִ밪�� �ٷ� �丶�䰡 ��� �ʹ� �ּ� ��¥
			if (visited[i][j] == -1 && arr[i][j] == 0) { // �ٵ� ���� �湮 �� �� �� ���� �丶�䰡 ����������
				cout << -1; return 0; // -1 ��� �� ����
			}
		}
	}
	cout << ans;
}