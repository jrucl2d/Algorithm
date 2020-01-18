#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000000

int arr[MAX];
int n;
vector<int> dp;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//int dp[MAX];
	//cin >> n;
	//for (int i = 0; i < n; i++) {
	//	cin >> arr[i];
	//	dp[i] = 1; // 최초에 자기 자신 넣기
	//	for (int j = 0; j < i; j++) { // 자신 이전 것 중에서
	//		if (arr[i] > arr[j] && dp[i] < dp[j] + 1) { // 원래 자신의 개수보다 이전 것에 자기 자신을 더한 것이 더 크면
	//			dp[i] = dp[j] + 1;
	//		}
	//	}
	//}
	//int ans = 0;
	//for (int i = 0; i < n; i++)
	//	ans = max(ans, dp[i]);
	// 위까지 O(n^2)의 식
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp.push_back(arr[0]); // 첫 요소 집어 넣기
	for (int i = 1; i < n; i++) {
		if (dp.back() < arr[i]) {
			dp.push_back(arr[i]);
		}
		else {
			auto it = lower_bound(dp.begin(), dp.end(), arr[i]); // lower_bound 구현
			*it = arr[i];
		}
	}
	cout << dp.size();
}