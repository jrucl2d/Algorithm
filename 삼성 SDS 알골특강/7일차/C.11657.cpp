#include <cstring>
#include <iostream>
#include <vector>
#define INF 1e18
using namespace std;
typedef pair<int, int> pr;
typedef long long ll;
int n, m;
ll dist[510];  // underflow�� �� �� �����Ƿ� ll���� ����� ��
vector<pr> adj[510];

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});  // a���� b���� ��� c
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;  // ������

    bool is_cycle = false;
    // n-1�� ��� �����ϰ� ������ �� ���� ������ ���� ����Ŭ �ľ�
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < adj[j].size(); k++) {
                int next_pos = adj[j][k].first;
                int next_cost = adj[j][k].second;
                // ���� ������ �����ϹǷ� INF�� �ƴ� ��쿡�� �ľ��Ѵ�.
                if (dist[j] != INF && dist[next_pos] > dist[j] + next_cost) {
                    dist[next_pos] = dist[j] + next_cost;
                    // ������ �� �� �� �� �� ���̰� �پ��� ����Ŭ ����
                    if (i == n) is_cycle = true;
                }
            }
        }
    }

    if (is_cycle) {
        cout << -1;
    } else {
        for (int i = 2; i <= n; i++) {
            cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
        }
    }
    return 0;
}