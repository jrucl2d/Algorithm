#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 16
#define INF 987654321

int n;
int w[MAX][MAX];
int dp[MAX][1 << MAX];  // [���� ����][�湮�� ��ġ��]

int dfs(int now, int visited_bits) {
    // üũ��
    visited_bits += (1 << now);

    // �Ϸ� ����
    if (visited_bits == (1 << n) - 1) {
        if (w[now][0] != 0)
            return w[now][0];
        else
            return INF;
    }
    // dp ����� ����
    int& ret = dp[now][visited_bits];
    if (ret != -1) return ret;

    ret = INF;
    // �� �� �ִ� ���� ����
    for (int i = 0; i < n; i++) {
        // ����
        if (visited_bits & (1 << i)) continue;  // �̹� �湮�� ��
        if (w[now][i] == 0) continue;           // ���� ���� ��
        // �� �� ������ �ش� ��ġ�� �湮 ó���ؼ� ��� ȣ��
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