#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000

int arr[MAX];
int n;
int dp[MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1; // 최초에 자기 자신 넣기
		for (int j = 0; j < i; j++) { // 자신 이전 것 중에서
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) { // 원래 자신의 개수보다 이전 것에 자기 자신을 더한 것이 더 크면
				dp[i] = dp[j] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}