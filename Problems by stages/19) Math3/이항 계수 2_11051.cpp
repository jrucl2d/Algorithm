#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 1001
int dp[MAX][MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j == 0 || i == j) {
				dp[i][j] = 1;
			}
			else if (j == 1) {
				dp[i][j] = i;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007; // ÆÄ½ºÄ® »ï°¢Çü
			}
		}
	}
	cout << dp[n][k];
}