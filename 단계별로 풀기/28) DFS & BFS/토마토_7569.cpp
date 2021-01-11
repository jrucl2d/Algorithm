#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100 + 1

int n, m, h; // 7576�� �������� ���������� �ٲ� ����
int arr[MAX][MAX][MAX];
int visited[MAX][MAX][MAX]; // ������ ���� ����
struct in {
	int x;
	int y;
	int z;
};
queue<in>q;

// ����
int dx[6] = { -1, 0, 0, 1, 0, 0 };
int dy[6] = { 0, -1, 0, 0, 1, 0 };
int dz[6] = { 0, 0, -1, 0, 0, 1 };

void bfs(int a, int b, int c) {
	while (!q.empty()) { // ť�� ���� �ʴ� ��
		a = q.front().x;
		b = q.front().y;
		c = q.front().z;

		q.pop(); // ���ʰ� ������

		for (int i = 0; i < 6; i++) { // �����¿� ���� ���� Ž��
			int na = a + dx[i];
			int nb = b + dy[i];
			int nc = c + dz[i];

			if (1 <= na && na <= n && 1 <= nb && nb <= m && 1 <= nc && nc <= h) { // ���� ������
				// ���� �� �� ���̰�, �ش� ��ġ�� ���� ���� �丶�䰡 ������
				if (visited[na][nb][nc] == -1 && arr[na][nb][nc] == 0) {
					q.push({ na, nb, nc }); // �ش� ��ġ ť�� �ְ�
					visited[na][nb][nc] = visited[a][b][c] + 1; // ��¥ �ϳ� ����
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> m >> n >> h;
	for (int k = 1; k <= h; k++) { // z���� ���� �޾ƾ� ��
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j][k];
				visited[i][j][k] = -1; // �湮�ߴ��� ������ �ʱⰪ ��� -1�� ����(��¥)
				if (arr[i][j][k] == 1) { // �̹� �;��ִ� �丶���
					q.push({ i,j,k }); // ť�� �ְ�
					visited[i][j][k] = 0; // �湮�ߴٰ� ǥ��(ù��)
				}
			}
			
		}
	}
	bfs(1, 1, 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= h; k++) {
				ans = max(ans, visited[i][j][k]); // ��¥ �߿��� �ִ밪�� �ٷ� �丶�䰡 ��� �ʹ� �ּ� ��¥
				if (visited[i][j][k] == -1 && arr[i][j][k] == 0) { // �ٵ� ���� �湮 �� �� �� ���� �丶�䰡 ����������
					cout << -1; return 0; // -1 ��� �� ����
				}
			}
		}
	}
	cout << ans;
}