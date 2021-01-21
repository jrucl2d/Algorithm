#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 16
#define INF 987654321

int n;
int w[MAX][MAX];
int dp[MAX][1 << MAX];  // [현재 상태][방문한 위치들]

int dfs(int now, int visited_bits) {
    // 체크인
    visited_bits += (1 << now);

    // 완료 조건
    if (visited_bits == (1 << n) - 1) {
        if (w[now][0] != 0)
            return w[now][0];
        else
            return INF;
    }
    // dp 존재시 리턴
    int& ret = dp[now][visited_bits];
    if (ret != -1) return ret;

    ret = INF;
    // 갈 수 있는 곳을 간다
    for (int i = 0; i < n; i++) {
        // 예외
        if (visited_bits & (1 << i)) continue;  // 이미 방문한 곳
        if (w[now][i] == 0) continue;           // 길이 없는 곳
        // 갈 수 있으면 해당 위치를 방문 처리해서 재귀 호출
        ret = min(ret, w[now][i] + dfs(i, visited_bits));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    memset(dp, 0xff, sizeof(dp));
    cout << dfs(0, 0);
}