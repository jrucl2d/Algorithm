#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 10000000
#define MAX 100 + 1

// �÷��̵� ���� �˰��� ���
// ���ͽ�Ʈ�� �˰����� �ϳ��� �������� ��� ���������� �ִܰŸ��� ���ϴ� �˰����̾���, 
// �÷��̵� ���� �˰����� ��� �������� ��� ���������� �ִܰŸ��� ���ϴ� �˰����̴�.
// ���İ��� ������ �������� �˰����� �����Ѵ�.

int n, m; // ����, ����
int arr[MAX][MAX];
int darr[MAX][MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (arr[a][b] > 0 && arr[a][b] > c) // a���� b�� ���� ��ΰ� ���� ��찡 ���� �� �����Ƿ� �� ª���� ����
			arr[a][b] = c; // a���� b�� ���� ��� c
		else if (arr[a][b] == 0) arr[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != 0)
				darr[i][j] = arr[i][j];
			else darr[i][j] = INF;
			if (i == j) darr[i][j] = 0; // �ڱ� �ڽ��� ������� ������ ���� �Ÿ��� 0
		}
	}

	for (int k = 1; k <= n; k++) { // ���İ��� �� k�� ���ؼ�
		for (int i = 1; i <= n; i++) { // ���� �� i
			for (int j = 1; j <= n; j++) { // ���� �� j
				 // ���İ��� �� k���� ����ϰų� �����ϴ� ���, �ڱ� �ڽ��� ������� ������ ��� ����
				if (i == j || i == k || j == k) continue;
				// ���� ���İ��� ��ΰ� �� ª���� ����
				if (darr[i][j] > darr[i][k] + darr[k][j])
					darr[i][j] = darr[i][k] + darr[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (darr[i][j] == INF)
				cout << 0 << " ";
			else cout << darr[i][j] << " ";
		}
		cout << "\n";
	}
}