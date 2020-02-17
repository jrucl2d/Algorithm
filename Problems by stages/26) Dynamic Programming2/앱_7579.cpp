#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// 발상의 전환 필요. dp에 i앱까지로 얻을 수 있는 최소 코스트를 저장하면 용량 초과.
// 따라서 j코스트로 얻을 수 있는 최대 메모리를 저장해야 한다.

int n, m;
int mem[100 + 1];
int cost[100 + 1];
int dp[100 + 1][10000 + 1]; // i까지의 앱 중 j 코스트로 얻을 수 있는 최대 메모리

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> mem[i];
	for (int i = 0; i < n; i++)
		cin >> cost[i];

	int ans = INT_MAX;
	// 0번째 앱만 있을 때 해당 코스트로 비활성화하면 해당 메모리만큼을 얻을 수 있다.
	dp[0][cost[0]] = mem[0];

	for (int i = 1; i < n; i++) { // i번째 앱을 비활성화할지 말지
		for (int j = 0; j <= 10000; j++) { // 최대 100개의 수가 최대 100 cost를 가지므로

			// i앱의 ocst가 j보다 크면 비활성화 못하므로 활성화 시켜둔다.
			// 예로, 처음 mem[0] = 30, cost[0] = 3이라고 하자.
			// 현재의 j가 1이면 0번째를 비활성화하는 데 드는 cost가 3이므로 못 끈다.
			if (cost[i] > j)
				dp[i][j] = dp[i - 1][j]; // 즉, 이전 i까지 결과와 같게 된다.

			// 만약 끌 수 있으면 현재 앱을 비활성화하고, 현재 앱을 끈 다음의 메모리와 
			// 안 끈 후의 메모리 중 큰 값을 dp에 저장한다.
			else {
				// 메모리를 끄면 최대 용량이 i앱의 용량만큼(mem[i]) 늘어난다. 이걸 어디에 더하냐,
				// 현재(i) 앱을 끈 상태에서 'j코스트인 상태'를 dp에 저장해야 하므로
				// 이전(i-1)에 j코스트에서 i의 코스트만큼 적은 상태의 dp에 더한다.
				dp[i][j] = max(mem[i] + dp[i - 1][j - cost[i]], dp[i - 1][j]);
			}
			if (dp[i][j] >= m) // 만약 현재의 dp값이 원하는 값 m보다 크거나 같게 되면
				ans = min(ans, j); // ans에 기존 값과 현재 얻을 수 있는 j코스트를 비교해서 작은 값 넣는다.
		}
	}
	cout << ans;
}