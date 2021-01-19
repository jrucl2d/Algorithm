#include <cstring>
#include <iostream>
#include <vector>
#define INF 1e18
using namespace std;
typedef pair<int, int> pr;
typedef long long ll;
int n, m;
ll dist[510];  // underflow가 날 수 있으므로 ll으로 해줘야 함
vector<pr> adj[510];

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});  // a에서 b까지 비용 c
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;  // 시작점

    bool is_cycle = false;
    // n-1로 모두 갱신하고 마지막 한 번의 루프로 음의 사이클 파악
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < adj[j].size(); k++) {
                int next_pos = adj[j][k].first;
                int next_cost = adj[j][k].second;
                // 음의 간선이 존재하므로 INF가 아닌 경우에만 파악한다.
                if (dist[j] != INF && dist[next_pos] > dist[j] + next_cost) {
                    dist[next_pos] = dist[j] + next_cost;
                    // 마지막 한 번 더 돌 때 길이가 줄어들면 사이클 존재
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