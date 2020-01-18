#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int tmp;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	int dp[100000];
	int ans = v[0];
	dp[0] = v[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + v[i], v[i]); // ���������� �ְ� ���ݰ� ���� �Ͱ� �׳� ���� �� ū �ɷ�
		ans = max(ans, dp[i]);
	}
	cout << ans;
}