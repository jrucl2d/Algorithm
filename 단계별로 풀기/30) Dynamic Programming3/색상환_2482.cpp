#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000003
#define MAX 1000 + 1

int dp[MAX][MAX]; // i����ȯ���� j���� ĥ�� ����� ��

int n, k;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> k;
	
	dp[1][1] = 1; // 1�� ���� ���� ĥ�ϸ� ����� �� �ϳ�.
	
	for (int i = 2; i <= n; i++) {
		int limit = i / 2; // ��ǻ� k�� n�� ������ �Ѿ�� �� 0�̴�.

		for (int j = 1; j <= limit; j++) {
			if (j == 1)
				dp[i][j] = i;
			else { // �̹��� ĥ�ϰų� �� ĥ�ϰų�.
				// ĥ�ϸ� "i - 2��°(�� ĭ �ǳ� �ٱ� ��)�� j - 1��ŭ ĥ�� ����� ��"�̰� 
				// �� ĥ�ϸ� "i - 1��°(�ٷ� ����)�� j��ŭ ĥ���� ����� ��"�̴�. ������ �̹��� �� ĥ�ϹǷ� ������ j��ŭ ĥ�߾ �ȴ�.
				dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
			}
		}
	}
	cout << dp[n][k];
}