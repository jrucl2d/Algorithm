#include <iostream>
using namespace std;
#define INF int(1e9)
int n, m;
int ans[110][110];

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n >> m;
    // �ʱⰪ INF�� �ʱ�ȭ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) ans[i][j] = INF;
    }
    // �ڱ� �ڽű����� ��� 0���� �ʱ�ȭ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) ans[i][j] = 0;  // �ڱ� �ڽ��� cost 0
        }
    }
    // ���� �Է� ����
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        ans[a][b] = min(ans[a][b], c);
    }
    // �÷��̵� �ͼ�
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