#include <iostream>
using namespace std;

int n, m, ans = 0;
int mem[110], cost[110];
// int dp[10010];  // cost i를 소모해서 확보할 수 있는 최대 메모리 크기
int dp[101][10001];  // [j][i] j 앱까지 cost i로 얻을 수 있는 최대 메모리 크기

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> mem[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    for (int j = 1; j <= 100; j++) {
        for (int i = 0; i <= 10000; i++) {
            // [j][i] : j 앱까지 고려했을 때 cost i로 확보할 수 있는 최대 메모리

            // j번째 앱을 사용하지 않으면 이전까지의 cost를 만드는 최대 금액
            dp[j][i] = dp[j - 1][i];
            // j번째 앱을 사용하면
            if (i - cost[j] >= 0) {
                // 현재 금액 뺀 만큼의 최대 메모리에 현재 금액을 추가
                dp[j][i] = max(dp[j][i], dp[j - 1][i - cost[j]] + mem[j]);
            }
        }
    }
    for (int i = 0; i <= 10000; i++) {
        if (dp[n][i] >= m) {
            ans = i;
            break;
        }
    }

    cout << ans;
    return 0;
}