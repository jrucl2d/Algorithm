#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
int n, dp[510][510];
vector<pii> v;

// 행렬의 s부터 e까지 계산해서 최적의 값을 리턴
int calc(int s, int e) {
    if (e - s == 1) {
        return v[s].first * v[s].second * v[e].second;
    }
    if (e == s) {
        return 0;
    }
    // calc(s, e)를 처음 계산하는 것이 아니면 dp를 리턴
    // 부분으로 나눠서 최적의 값을 구함
    // 자르는 부분을 s와 그 이후, s+1와 그 이후... s~e-1과 e 까지
    if (dp[s][e] != 0) return dp[s][e];
    int min_val = 1e9;
    for (int mid = s; mid < e; mid++) {
        // 부분에서 나온 결과와 전체의 결과를 더해줌
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