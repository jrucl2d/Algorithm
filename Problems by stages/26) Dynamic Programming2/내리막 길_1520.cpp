#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 500 + 1
int dp[MAX][MAX]; // �������� ���� i,j ��ġ���� ���� �ִ� ����� ��
int arr[MAX][MAX];
int m, n;

int dir[4][2] = { {-1,0}, {0,-1}, {1,0} , {0,1} }; // �����¿� ����

// DFS + DP�� Ǯ��. 
int func(int y, int x) {
	if (y == m && x == n) return 1; // �������, ���� �����ϸ� Ż��
	int& tmp = dp[y][x]; // dp ���� ������ ����
	if (tmp != -1) return tmp; // ���� -1�� �ƴϸ� ����(-1�� �ʱ�ȭ�Ǿ� �����Ƿ�)
	tmp = 0; // �ش� ��ġ�� �������� ������ 0���� �������(���� ���� -1�� ����ȭ)
	for (int i = 0; i < 4; i++) {
		int nexty = y + dir[i][1]; // ��, ��(��)
		int nextx = x + dir[i][0]; // ��, ��(��)

		// dp�� ���� ������ ���������� ���
		if (m >= nexty && nexty > 0 && n >= nextx && nextx > 0) {
			if (arr[nexty][nextx] < arr[y][x])
				tmp += func(nexty, nextx); // ���� ��ġ�� dp���� �����ش�.
		}
	}
	return tmp; // �ش� ��ġ������ dp�� ����
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1; // dp���� ��� -1�� �ʱ�ȭ
		}
	}
	cout << func(1, 1);
}