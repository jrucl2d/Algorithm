#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 100 + 1
#define Mod 1000000000

int n;
int dp[MAX][10]; // �� �ڸ���, �������ڸ� ����, i �ڸ����� ���� �� j�� ������ ��.
// i�ڸ� �� �� j�� ������ ���� i-1�ڸ� �� �� j-1�� ������ ���� j+1�� ������ ���� ��
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1; // 0���� �����ϴ� ���ڰ� �����Ƿ�
	}
	for (int i = 2; i <= n; i++) { 
		for (int j = 0; j <= 9; j++) {
			// i�ڸ� �� �� 0���� ������ ������ i-1�ڸ� �� �� 1�� ������ �������� �� �� �ִ�.
			if (j == 0) dp[i][j] = dp[i - 1][1] % Mod; 
			else if (j == 9) dp[i][j] = dp[i - 1][8] % Mod; // 8������ �� �� �ִ�.
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % Mod;
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[n][i]) % Mod;
	}
	cout << sum % Mod;
}