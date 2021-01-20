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
        // ���� ���� ������� ���� �� �� �� ������ ����� ��
        // ���� ���� �� ������� �� �� �� �Ϳ��� ���� ��
        dp[i] = dp[i - 3] + stair[i - 1] + stair[i];
        dp[i] = max(dp[i], dp[i - 2] + stair[i]);
    }
    cout << dp[n];
    return 0;
}