#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define MAX 1000 + 1
struct in {
	int first;
	int second;
	int flag;
};
int arr[MAX][MAX];
int visited[MAX][MAX][2]; // �������� ���� �վ����� ���θ� ��Ÿ�� flag �ϳ� �߰�
int n, m;

int bfs(int a, int b) {
	queue<in>q;
	q.push({ a, b, 0 });
	visited[a][b][0] = 1; // ���� ���� ����, ���� �� �� ����

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int c = 0; // �� �վ����� ���� ������ ����

	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		c = q.front().flag;

		q.pop();
		if (a == n && b == m) // ���������� �����ϸ� ����
			return visited[a][b][c];

		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (1 <= na && na <= n && 1 <= nb && nb <= m) {
				if (visited[na][nb][c] == 0 && arr[na][nb] == 0) { // �⺻������ ���� �ִµ�, ���� �� ������
					q.push({ na,nb,c });
					visited[na][nb][c] = visited[a][b][c] + 1;
				}
				if (arr[na][nb] == 1 && c == 0) { // ���� ���� �ִµ�, ���� �� �վ��ٸ�
					visited[na][nb][1] = visited[a][b][c] + 1; // �ձ� �� �Ϳ� 1�� ���Ѵ�.
					q.push({ na, nb, 1 }); // ���� ������ ��츦 ť�� �߰��Ѵ�.(���⼭ �Ļ��Ǹ� c�� 1�� ä�� ����ȴ�.)
				}
			}
		}
	}
	return -1; // ���� n, m���� �� ���� ť�� ��������(���� �� ������ �Ǹ�) -1 ���
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
	cout << bfs(1, 1);
}