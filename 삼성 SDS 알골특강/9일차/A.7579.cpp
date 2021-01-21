#include <iostream>
using namespace std;

int n, m, ans = 0;
int mem[110], cost[110];
// int dp[10010];  // cost i�� �Ҹ��ؼ� Ȯ���� �� �ִ� �ִ� �޸� ũ��
int dp[101][10001];  // [j][i] j �۱��� cost i�� ���� �� �ִ� �ִ� �޸� ũ��

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
            // [j][i] : j �۱��� ������� �� cost i�� Ȯ���� �� �ִ� �ִ� �޸�

            // j��° ���� ������� ������ ���������� cost�� ����� �ִ� �ݾ�
            dp[j][i] = dp[j - 1][i];
            // j��° ���� ����ϸ�
            if (i - cost[j] >= 0) {
                // ���� �ݾ� �� ��ŭ�� �ִ� �޸𸮿� ���� �ݾ��� �߰�
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