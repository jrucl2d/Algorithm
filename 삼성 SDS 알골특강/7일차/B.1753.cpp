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
    // ������ �Ÿ� ���� + pq�� �Է�
    dist[start_point] = 0;
    pq.push({0, start_point});  // �������� ��ġ�� �Ÿ��� push

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_pos = pq.top().second;
        pq.pop();

        // �̹� ó���� ��� ��ŵ
        if (dist[now_pos] < now_cost) continue;

        // now�� �ֺ��� Ž��
        for (int i = 0; i < adj[now_pos].size(); i++) {
            int next_cost = adj[now_pos][i].first;
            int next_pos = adj[now_pos][i].second;
            // ���� ���� ���ؼ� ���� ������ �̵��ϴ� �� ��� ���
            int the_cost = now_cost + next_cost;
            // ���� ���� ���ؼ� ���� ���� �� ����� ���ٸ�
            if (the_cost < dist[next_pos]) {
                dist[next_pos] = the_cost;  // ��� ������Ʈ
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
        adj[a].push_back({c, b});  // a���� b�� ���� �� c�� ����ġ
    }
    // dist �迭 �ʱ�ȭ
    for (int i = 1; i <= v; i++) {
        dist[i] = INF;
    }
    // dijstra
    dijstra();

    // ���
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
            continue;
        }
        cout << dist[i] << "\n";
    }
    return 0;
}