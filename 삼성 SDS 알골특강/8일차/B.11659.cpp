#include <cstdio>
using namespace std;
int n, m, arr[100010], dp[100010];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = dp[i - 1] + arr[i];
    }
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", dp[b] - dp[a] + arr[a]);
    }
    return 0;
}