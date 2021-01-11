#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000003
#define MAX 1000 + 1

int dp[MAX][MAX]; // i색상환에서 j개를 칠한 경우의 수

int n, k;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> k;
	
	dp[1][1] = 1; // 1개 있을 때는 칠하면 경우의 수 하나.
	
	for (int i = 2; i <= n; i++) {
		int limit = i / 2; // 사실상 k가 n의 절반을 넘어가면 다 0이다.

		for (int j = 1; j <= limit; j++) {
			if (j == 1)
				dp[i][j] = i;
			else { // 이번에 칠하거나 안 칠하거나.
				// 칠하면 "i - 2번째(한 칸 건너 뛰기 전)에 j - 1만큼 칠한 경우의 수"이고 
				// 안 칠하면 "i - 1번째(바로 이전)에 j만큼 칠했을 경우의 수"이다. 어차피 이번에 안 칠하므로 이전에 j만큼 칠했어도 된다.
				dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
			}
		}
	}
	cout << dp[n][k];
}