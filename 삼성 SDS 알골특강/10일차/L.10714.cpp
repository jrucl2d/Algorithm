#include <iostream>

using namespace std;
typedef long long ll;
int n, cake[2010];
// JOI군이 바라볼 때 왼쪽에 i번째 케이크, 오른쪽에 j번째 케이크
// 이 때 가장 많이 먹을 수 있는 케이크 값
ll dp[2010][2010];

ll J_eat(int l, int r);
ll I_eat(int l, int r);

// j군이 먹을 차례에 왼쪽은 l 케이크, 오른쪽은 r케이크
ll J_eat(int l, int r) {
    if (l == r) return cake[l];
    if (dp[l][r] != -1) return dp[l][r];
    // 먹을 수 있는 경우의 수
    // l을 먹거나 -> cake[l]
    int nextl, nextr;
    nextl = l + 1;
    if (nextl == n) nextl = 0;

    // r을 먹거나 -> cake[r]
    nextr = r - 1;
    if (nextr < 0) nextr = n - 1;

    return dp[l][r] = max(cake[l] + I_eat(nextl, r), cake[r] + I_eat(l, nextr));
}
// i양이 먹을 차례 -> i양이 많이 먹을 수 있는 값
// i양이 먹을 차례 -> j군이 많이 먹을 수 있는 값
ll I_eat(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    // 무조건 큰 것만 먹음
    if (cake[l] > cake[r]) {
        int nextl = l + 1;
        if (nextl == n) nextl = 0;
        return dp[l][r] = J_eat(nextl, r);
    } else {
        int nextr = r - 1;
        if (nextr < 0) nextr = n - 1;
        return dp[l][r] = J_eat(l, nextr);
    }
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cake[i];
    }
    for (int i = 0; i < 2010; i++) {
        for (int j = 0; j < 2010; j++) {
            dp[i][j] = -1;
        }
    }
    ll ans = 0;
    // i번째 케이크를 J군이 먹고 시작
    for (int i = 0; i < n; i++) {
        int nextl, nextr;
        nextl = i + 1;
        if (nextl == n) nextl = 0;
        nextr = i - 1;
        if (nextr < 0) nextr = n - 1;
        ans = max(ans, cake[i] + I_eat(nextl, nextr));
    }
    cout << ans;
    return 0;
}