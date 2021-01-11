#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset ��� ����
using namespace std;
#define MAX 50 + 1

int t;
int m, n, k;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int cnt = 0;


void dfs(int a, int b) {
	if (arr[a][b] == 0) // �ش� �ڸ��� 0�̸� �׳� ����
		return;
	visited[a][b] = true; // �ش� �ڸ� �Դ� ������ ǥ��
	cnt++; // �� ī��Ʈ
	// ��
	if (visited[a - 1][b] != true && arr[a - 1][b] == 1) {
		dfs(a - 1, b); // ������ dfs�� ����
		arr[a - 1][b] = 0; // �̹� ������ �ڸ��� 0���� ��������
	}
	// ��
	if (visited[a + 1][b] != true && arr[a + 1][b] == 1) {
		dfs(a + 1, b);
		arr[a + 1][b] = 0;
	}
	// ��
	if (visited[a][b - 1] != true && arr[a][b - 1] == 1) {
		dfs(a, b - 1);
		arr[a][b - 1] = 0;
	}
	// ��
	if (visited[a][b + 1] != true && arr[a][b + 1] == 1) {
		dfs(a, b + 1);
		arr[a][b + 1] = 0;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> t;
	while (t-- > 0) {
		cin >> m >> n >> k; // [n][m]�̴�.

		// ��� �迭�� �ʱ�ȭ
		memset(arr, 0, sizeof(arr)); 
		memset(visited, false, sizeof(visited));

		int tmp1, tmp2;
		while (k-- > 0) {
			cin >> tmp1 >> tmp2;
			arr[tmp2 + 1][tmp1 + 1] = 1; // ���Ǹ� ���� 1,1���� �����ϵ���
		}
		int ans = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cnt = 0; // �Ź� cnt�� 0���� �ʱ�ȭ
				dfs(i, j); // ��� ��쿡 ���ؼ� dfs ����
				if (cnt != 0)
					ans++;
			}
		}
		cout << ans << "\n";
	}
}