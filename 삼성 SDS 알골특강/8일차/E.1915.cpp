#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, m, arr[1010][1010], dp[1010][1010], ans = 0;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            arr[i][j] = tmp[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 1) {
            dp[i][0] = 1;
            ans = 1;
        }
    }
    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 1) {
            dp[0][j] = 1;
            ans = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            // 위, 옆, 대각선 중 가장 작은 정사각형에 1을 더한 것이 지금것
            if (dp[i - 1][j - 1] != 0 && dp[i - 1][j] != 0 &&
                dp[i][j - 1] != 0 && arr[i][j] == 1) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                dp[i][j] += 1;
                ans = max(ans, dp[i][j]);
            } else if (arr[i][j] == 1) {
                dp[i][j] = 1;
            }
        }
    }

    cout << ans * ans;
    return 0;
}