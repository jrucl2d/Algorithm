#include <iostream>
using namespace std;

int n;

int main() {
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	int dp1[3] = { a, b, c };
	int dp2[3] = { a, b, c };
	for (int i = 1; i < n; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		int left = 0, mid = 0, right = 0;
		left = max(dp1[0], dp1[1]) + t1;
		mid = max(dp1[0], max(dp1[1], dp1[2])) + t2;
		right = max(dp1[1], dp1[2]) + t3;
		dp1[0] = left, dp1[1] = mid, dp1[2] = right;

		left = min(dp2[0], dp2[1]) + t1;
		mid = min(dp2[0], min(dp2[1], dp2[2])) + t2;
		right = min(dp2[1], dp2[2]) + t3;
		dp2[0] = left, dp2[1] = mid, dp2[2] = right;
	}

	cout << max(dp1[0], max(dp1[1], dp1[2])) << " ";
	cout << min(dp2[0], min(dp2[1], dp2[2]));
	return 0;
}