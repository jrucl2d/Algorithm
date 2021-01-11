#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000
#define MAX 400 + 1
int v, e;
int arr[MAX][MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> v >> e;
	for (int i = 0; i < MAX; i++) { // ��� ���� INF�� �ʱ�ȭ
		for (int j = 0; j < MAX; j++) {
			arr[i][j] = INF;
		}
	}

	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr[a][b] = c; // a���� b�� ���� ����� c
	}

	for (int k = 1; k <= v; k++) { // ���İ��� �� k
		for (int i = 1; i <= v; i++) { // ������ i
			for (int j = 1; j <= v; j++) { // ������ j
				// ���� ���İ��� ��ΰ� �� ª���� ����
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= v; i++) { // �ڱ� �ڽ����� ���� ��� ��쿡 ���ؼ�
		ans = min(ans, arr[i][i]);
	}
	if (ans != INF)
		cout << ans;
	else cout << -1;
}