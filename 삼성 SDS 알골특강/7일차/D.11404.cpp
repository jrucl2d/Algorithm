#include <iostream>
using namespace std;
#define INF int(1e9)
int n, m;
int ans[110][110];

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n >> m;
    // 초기값 INF로 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) ans[i][j] = INF;
    }
    // 자기 자신까지의 비용 0으로 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) ans[i][j] = 0;  // 자기 자신의 cost 0
        }
    }
    // 간선 입력 받음
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        ans[a][b] = min(ans[a][b], c);
    }
    // 플로이드 와샬
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
	    if(ans[i][k] == INF || ans[k][j] == INF) continue;
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (ans[i][j] == INF ? 0 : ans[i][j]) << " ";
        }
        cout << "\n";
    }

    return 0;
}