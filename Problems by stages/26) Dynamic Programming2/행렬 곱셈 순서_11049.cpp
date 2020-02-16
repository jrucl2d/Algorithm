#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
#define MAX  500 + 1

// dp[i][j]�� �߰��� k�� �������� dp[i][k] + dp[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1]
// �� ������ ���� �� �ִ�. �ڿ� �����ִ� �κ��� ù ����� ��, ��� ����� ��, ������ ����� ����
// ���ؾ� �ϱ� �����̴�.

int dp[MAX][MAX]; // i���� j���� ���� ���� �ּҰ�
int matrix[MAX][2]; // 0���� ��, 1���� ���� ����.

int n;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) { // ��� ���� ������� �Է¹���
		cin >> matrix[i][0] >> matrix[i][1];
	}
	for (int i = 1; i < n; i++) // ���̰� �ϳ� ���� ���� �� �� �׳� �����ش�.
		dp[i][i + 1] = matrix[i][0] * matrix[i][1] * matrix[i + 1][1];

	for (int tmp = 2; tmp < n; tmp++) { // �� ������ ����
		for (int i = 1; i <= n - tmp; i++) { // i�� 1���� n - 1����
			int j = tmp + i; // j�� 2���� n����
			dp[i][j] = INT_MAX;
			for (int mid = i; mid < j; mid++) {
				// dp[i][j]�� ��� �߰��� mid�� ���ؼ� ���غ���. �� �� ���� ���� ������ ����
				dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + matrix[i][0] * matrix[mid][1] * matrix[j][1]);
			}
		}
	}
	cout << dp[1][n] << "\n";
}