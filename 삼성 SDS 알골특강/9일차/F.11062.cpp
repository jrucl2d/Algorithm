#include <cstring>
#include <iostream>
using namespace std;

int t, n, card[1010], sums[1010], ans = 0, k_dp[1010][1010], m_dp[1010][1010];

int get_sum(int s, int e) { return sums[e] - sums[s - 1]; }

int k_play(int s, int e);
int m_play(int s, int e);

int k_play(int s, int e) {
    if (s == e) return card[s];

    // 근우가 이번에 얻는 값 : card[s]
    // 명우가 최선을 다한 값 : m_play(s + 1, e)
    // 근우가 나머지 플레이에서 얻는 점수
    // : [s+1 ~ e] - 명우가 최선을 다해 얻는 점수

    if (k_dp[s][e] != -1) return k_dp[s][e];

    // 가장 왼쪽을 가져감
    int left = card[s] + get_sum(s + 1, e) - m_play(s + 1, e);

    // 가장 오른쪽을 가져감
    int right = card[e] + get_sum(s, e - 1) - m_play(s, e - 1);

    return k_dp[s][e] = max(left, right);
}
int m_play(int s, int e) {
    if (s == e) return card[s];

    if (m_dp[s][e] != -1) return m_dp[s][e];

    int left = card[s] + get_sum(s + 1, e) - k_play(s + 1, e);
    int right = card[e] + get_sum(s, e - 1) - k_play(s, e - 1);
    return m_dp[s][e] = max(left, right);
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n;
        memset(k_dp, 0xff, sizeof(k_dp));
        memset(m_dp, 0xff, sizeof(m_dp));
        for (int i = 1; i <= n; i++) {
            cin >> card[i];
            sums[i] = sums[i - 1] + card[i];
        }
        cout << k_play(1, n) << "\n";
    }
    return 0;
}