#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n;
vector<ll> dp(91, -1);

ll sol(ll index) {
	if (index <= 2) {
		return dp[index];
	}
	if (dp[index] != -1) {
		return dp[index];
	}
	dp[index] = sol(index - 1) + sol(index - 2);
	return dp[index];
}

int main() {
	cin >> n;
	dp[0] = 0;
	dp[1] = dp[2] = 1;

	cout << sol(n);
	return 0;
}