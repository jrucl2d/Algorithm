#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;

int dp[201][201];
int n, m, k;
vector<char> ans;

int combination(int i, int j) {
	if (i == j || j == 0) {
		return 1;
	}
	else {
		if (dp[i][j] != 0) {
			return dp[i][j];
		}
		return dp[i][j] = min(combination(i - 1, j - 1) + combination(i - 1, j), MAX);
	}

	return 0;
}

void sol(int n, int m, int k) {
	// n == 0 && m == 0
	if (n + m == 0) {
		return;
	}
	// n == 0
	else if (n == 0) {
		ans.push_back('z');
		sol(n, m - 1, k);
	}
	// m == 0
	else if (m == 0) {
		ans.push_back('a');
		sol(n - 1, m, k);
	}
	// n+m-1 C m
	else {
		int border = combination(n + m - 1, m); // a를 하나 골랐을 때의 범위
		if (border >= k) {
			// 위로 간다.
			ans.push_back('a');
			sol(n - 1, m, k);
		}
		else {
			// 아래로 간다.
			ans.push_back('z');
			sol(n, m - 1, k - border);
		}
	}
}

int main() {
	cin >> n >> m >> k;

	if (combination(n + m, m) < k) {
		cout << -1;
		return 0;
	}
	sol(n, m, k);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	return 0;
}