#include <iostream>
#include <queue>
#include <vector>
#define INF 987654312
using namespace std;

typedef pair<int, int> p;

int v, e, start_point;
vector<p> adj[20010];
int dist[20010];

void dijstra() {
    priority_queue<p> pq;
    // 시작점 거리 세팅 + pq에 입력
    dist[start_point] = 0;
    pq.push({0, start_point});  // 시작점의 위치와 거리를 push

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_pos = pq.top().second;
        pq.pop();

        // 이미 처리한 경우 스킵
        if (dist[now_pos] < now_cost) continue;

        // now의 주변을 탐색
        for (int i = 0; i < adj[now_pos].size(); i++) {
            int next_cost = adj[now_pos][i].first;
            int next_pos = adj[now_pos][i].second;
            // 현재 점을 통해서 다음 점으로 이동하는 데 드는 비용
            int the_cost = now_cost + next_cost;
            // 현재 점을 통해서 가는 것이 더 비용이 적다면
            if (the_cost < dist[next_pos]) {
                dist[next_pos] = the_cost;  // 비용 업데이트
                pq.push({-the_cost, next_pos});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> v >> e >> start_point;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});  // a에서 b로 가는 데 c의 가중치
    }
    // dist 배열 초기화
    for (int i = 1; i <= v; i++) {
        dist[i] = INF;
    }
    // dijstra
    dijstra();

    // 출력
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
            continue;
        }
        cout << dist[i] << "\n";
    }
    return 0;
}