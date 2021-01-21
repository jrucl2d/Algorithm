#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Info {
   public:
    int p1, p2;
    Info(){};
};

string a, b;
int dp[1010][1010];
Info track[1010][1010];  // track을 쓰지 않고도 구할 수 있음을 알고있기
vector<char> ans;

// p1, p2까지의 것들 중 LCS(반드시 p1, p2를 포함할 필요는 없음)
int sol(int p1, int p2) {
    if (p1 < 0 || p2 < 0) return 0;
    if (dp[p1][p2] != -1) return dp[p1][p2];
    // 같으면
    if (a[p1] == b[p2]) {
        dp[p1][p2] = sol(p1 - 1, p2 - 1) + 1;
        track[p1][p2].p1 = p1 - 1;
        track[p1][p2].p2 = p2 - 1;
        return dp[p1][p2];
    }
    // 다르면
    int tmp1, tmp2;
    tmp1 = sol(p1 - 1, p2);
    tmp2 = sol(p1, p2 - 1);
    if (tmp1 > tmp2) {
        dp[p1][p2] = tmp1;
        track[p1][p2].p1 = p1 - 1;
        track[p1][p2].p2 = p2;
    } else {
        dp[p1][p2] = tmp2;
        track[p1][p2].p1 = p1;
        track[p1][p2].p2 = p2 - 1;
    }
    return dp[p1][p2];
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    for (int i = 0; i < 1010; i++) {
        for (int j = 0; j < 1010; j++) {
            dp[i][j] = -1;
        }
    }
    cout << sol(a.length() - 1, b.length() - 1) << "\n";
    int t1 = a.length() - 1, t2 = b.length() - 1;

    while (true) {
        if (t1 < 0 || t2 < 0) break;
        if (a[t1] == b[t2]) {
            ans.push_back(a[t1]);
        }
        Info next = track[t1][t2];
        t1 = next.p1;
        t2 = next.p2;
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];

    return 0;
}