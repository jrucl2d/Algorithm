#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define MAX 100 + 1

int n, m;
int arr[MAX][MAX];
int visited[MAX][MAX]; // ������ ���� ����

void bfs(int a, int b) {
	queue<pair<int,int>>q;
	q.push({ a,b });
	visited[a][b] = 1; // ó��(1,1)�� �Ÿ� 1
	// ����
	int lr[4] = { -1,0,1,0 };
	int ud[4] = { 0,1,0,-1 };

	while (!q.empty()) { // ť�� ���� �ʴ� ��

		a = q.front().first;
		b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) { // �����¿� �׹��� Ž��
			int na = a + lr[i];
			int nb = b + ud[i];
			if (1 <= na && na <= n && 1 <= nb && nb <= m) { // ���� ������
				// ���� �� �� ���̰�, �ش� ��ġ�� ���� ������
				if (visited[na][nb] == 0 && arr[na][nb] == 1) {
					q.push({ na, nb }); // �ش� ��ġ ť�� �ְ�
					visited[na][nb] = visited[a][b] + 1; // �� �Ÿ� �ϳ� ����
				}
				else if (visited[na][nb] == 0) // �� �� ���̱� �ѵ� ���� ������
					visited[na][nb] = -1; // -1�� �ʱ�ȭ
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++)
			arr[i][j] = s[j - 1] - '0';
	}

	bfs(1, 1);
	cout << visited[n][m];
}