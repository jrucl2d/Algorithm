#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000 + 1
#define INF 1000000
int cost[MAX][3]; // i번째 집을 j의 색깔로 칠할 때 드는 비용
int dp[MAX][3]; 

int n;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];
	}
	int ans = INF;
	for (int color = 0; color < 3; color++) { // 세 번 반복
		for (int i = 0; i < 3; i++) { // 현재 color 색의 차례이면
			if (i == color) dp[0][i] = cost[0][i]; // 해당 dp[0]은 color색으로 칠하고
			else dp[0][i] = INF; // 나머지는 INF로 초기화. min으로 거르므로 첫번째는 무조건 color색을 칠한 것이 됨.
		}
		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0]; // 세 가지 경우에 대해서 계산
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[i][2];
		}
		for (int i = 0; i < 3; i++) {
			if (i == color) continue; // 첫 색깔이 color이므로 끝 색깔이 color일 수는 없다.
			else ans = min(ans, dp[n - 1][i]);
		}
	}
	cout << ans;
}