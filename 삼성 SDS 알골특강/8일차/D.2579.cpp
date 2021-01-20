#include <iostream>

using namespace std;
int n, stair[310], dp[310];

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> stair[i];
    }
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    for (int i = 3; i <= n; i++) {
        // 이전 것을 밟았으면 이전 것 두 개 전것을 밟았을 것
        // 이전 것을 안 밟았으면 두 개 전 것에서 왔을 것
        dp[i] = dp[i - 3] + stair[i - 1] + stair[i];
        dp[i] = max(dp[i], dp[i - 2] + stair[i]);
    }
    cout << dp[n];
    return 0;
}