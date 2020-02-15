#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 500 + 1

int t;
int k;
int dp[MAX][MAX];
int sum[MAX]; // 0부터 i까지의 합

// dp[i][j]를 i부터 j까지의 최소 비용이라고 가정. 
// dp[i][i] = v[i], dp[i][i+1] = v[i] + v[i+1]이다.
// 즉, dp[i][j]는 dp[i][mid] + dp[mid + 1][j]의 모든 경우 중 가장 최소값에 
// 마지막에 i부터 j까지의 값으로 만드는 데 드는 비용 sum[i - 1]~sum[j]를 더해준다.

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> t;

	while (t-- > 0) {
		cin >> k;
		int tmp;
		vector<int> v;
		for (int i = 1; i <= k; i++) {
			cin >> tmp; v.push_back(tmp);
			sum[i] = sum[i - 1] + tmp; // 0부터 해당 인덱스까지의 합을 계속 계산해줌.
		}

		for (int temp = 1; temp < k; temp++) {
			for (int i = 1; i <= k - temp; i++) {
				int j = i + temp;
				dp[i][j] = 1000000000; // 적당히 큰 수로 초기화

				for (int mid = i; mid < j; mid++) // i~j까지의 합이므로 sum[j] - sum[i - 1]이 맞다.
					dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + sum[j] - sum[i - 1]);
			}
		}
		cout << dp[1][k] << "\n";
	}

}