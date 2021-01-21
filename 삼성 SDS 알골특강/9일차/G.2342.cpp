#include <iostream>
#define INF 987654321

using namespace std;

int arr[100010], n = 0;
int dp[100010][5][5];  // [DDR 단계][왼발][오른발]의 최대 cost

int get_cost(int s, int e) {
    if (s == e) return 1;
    switch (s) {
        case 0:
            return 2;
        case 1:
            if (e == 2 || e == 4)
                return 3;
            else
                return 4;
        case 2:
            if (e == 1 || e == 3)
                return 3;
            else
                return 4;
        case 3:
            if (e == 2 || e == 4)
                return 3;
            else
                return 4;
        case 4:
            if (e == 1 || e == 3)
                return 3;
            else
                return 4;
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true) {
        cin >> arr[n + 1];  // 1 ~ n
        if (arr[n + 1] == 0) break;
        n += 1;
    }

    // dp 초기화
    for (int i = 0; i < 100010; i++) {
        for (int l = 0; l <= 4; l++) {
            for (int r = 0; r <= 4; r++) {
                dp[i][l][r] = INF;
            }
        }
    }
    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        // i 단계의 결과를 얻은 상태. i + 1 단계로 넘어가려고 함.
        // 다음에 밟아야 할 DDR 번호는 i + 1일 예정.
        for (int l = 0; l <= 4; l++) {
            for (int r = 0; r <= 4; r++) {
                // dp[i][l][r] : i단계일 때 l, r에서의 cost
                int n_pos = arr[i + 1];  // 다음에 가야 하는 위치

                // 왼발을 움직임 -> 그 위치에 오른 발이 없을 때, 더 cost가 적을 때만
                int the_power = dp[i][l][r] + get_cost(l, n_pos);
                if (n_pos != r && the_power < dp[i + 1][n_pos][r]) {
                    dp[i + 1][n_pos][r] = the_power;
                }
                // 오른발을 움직임
                the_power = dp[i][l][r] + get_cost(r, n_pos);
                if (n_pos != l && the_power < dp[i + 1][l][n_pos]) {
                    dp[i + 1][l][n_pos] = the_power;
                }
            }
        }
    }
    int ans = INF;
    for (int l = 0; l <= 4; l++) {
        for (int r = 0; r <= 4; r++) {
            ans = min(ans, dp[n][l][r]);
        }
    }
    cout << ans;

    return 0;
}