#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 10000 + 1
int grape[MAX];
int dp[MAX];

int main() { // LCS 구현
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> grape[i];
	}
	dp[1] = grape[1];
	dp[2] = max(grape[1], grape[1] + grape[2]);

	for (int i = 3; i <= n; i++) {
		// 이전 것을 먹은 경우 그 전 것은 못 먹고 전전것은 먹었다.
		// 이전 것을 못 먹은 경우 그 전전 것을 먹었다.
		dp[i] = max(grape[i] + grape[i - 1] + dp[i - 3], grape[i] + dp[i - 2]);
		dp[i] = max(dp[i], dp[i - 1]); // 연속 두 번 안 먹는 경우를 위해 이전 것과 비교
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}