#include <iostream>
#define INF 987654321

using namespace std;

int arr[100010], n = 0;
int dp[100010][5][5];  // [DDR �ܰ�][�޹�][������]�� �ִ� cost

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

    // dp �ʱ�ȭ
    for (int i = 0; i < 100010; i++) {
        for (int l = 0; l <= 4; l++) {
            for (int r = 0; r <= 4; r++) {
                dp[i][l][r] = INF;
            }
        }
    }
    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        // i �ܰ��� ����� ���� ����. i + 1 �ܰ�� �Ѿ���� ��.
        // ������ ��ƾ� �� DDR ��ȣ�� i + 1�� ����.
        for (int l = 0; l <= 4; l++) {
            for (int r = 0; r <= 4; r++) {
                // dp[i][l][r] : i�ܰ��� �� l, r������ cost
                int n_pos = arr[i + 1];  // ������ ���� �ϴ� ��ġ

                // �޹��� ������ -> �� ��ġ�� ���� ���� ���� ��, �� cost�� ���� ����
                int the_power = dp[i][l][r] + get_cost(l, n_pos);
                if (n_pos != r && the_power < dp[i + 1][n_pos][r]) {
                    dp[i + 1][n_pos][r] = the_power;
                }
                // �������� ������
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