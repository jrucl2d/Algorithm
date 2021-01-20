#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
int n, dp[510][510];
vector<pii> v;

// ����� s���� e���� ����ؼ� ������ ���� ����
int calc(int s, int e) {
    if (e - s == 1) {
        return v[s].first * v[s].second * v[e].second;
    }
    if (e == s) {
        return 0;
    }
    // calc(s, e)�� ó�� ����ϴ� ���� �ƴϸ� dp�� ����
    // �κ����� ������ ������ ���� ����
    // �ڸ��� �κ��� s�� �� ����, s+1�� �� ����... s~e-1�� e ����
    if (dp[s][e] != 0) return dp[s][e];
    int min_val = 1e9;
    for (int mid = s; mid < e; mid++) {
        // �κп��� ���� ����� ��ü�� ����� ������
        int tmp = calc(s, mid) + calc(mid + 1, e) +
                  v[s].first * v[mid].second * v[e].second;
        min_val = min(min_val, tmp);
    }
    return dp[s][e] = min_val;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        v.push_back({r, c});
    }
    cout << calc(0, n - 1);
    return 0;
}