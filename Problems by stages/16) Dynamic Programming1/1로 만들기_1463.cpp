#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 1000001
int n;
int dp[MAX];

int func() {
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1; // n-1을 최소로 만드는 횟수 + 1
		if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]); // n/2를 최소로 만드는 횟수 + 1과 비교
		if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]); // n/3을 최소로 만드는 횟수 + 1과 비교
	}
	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	dp[1] = 0; dp[2] = 1; dp[3] = 1;
	cout << func();
}