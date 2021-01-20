#include <cstdio>

using namespace std;
int n, m, arr[1025][1025], dp[1025][1025];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
            dp[i][j] =
                dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }

    while (m--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int ans = dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1];
        printf("%d\n", ans);
    }
    return 0;
}