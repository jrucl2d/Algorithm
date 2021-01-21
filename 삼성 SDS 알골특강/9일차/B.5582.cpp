#include <iostream>
#include <string>

using namespace std;
string a, b;
int ans = 0;
int dp[4010][4010];

// a, b가 각각 p1, p2로 끝나는 문자열의 LCS
int sol(int p1, int p2) {
    if (p1 < 0 || p2 < 0) {
        return 0;
    }
    // 현재 두 문자가 같으면 dp[i-1][j-1]에 1을 더한다.
    if (a[p1] == b[p2]) {
        if (dp[p1][p2] != -1) return dp[p1][p2];
        dp[p1][p2] = sol(p1 - 1, p2 - 1) + 1;
        return dp[p1][p2];
    } else
        return 0;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++) dp[i][j] = -1;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            ans = max(ans, sol(i, j));
        }
    }

    cout << ans;
    return 0;
}