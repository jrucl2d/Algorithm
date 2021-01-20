#include <iostream>
#include <vector>
#define INF 987654321
#define TOMB 1
using namespace std;

class Info {
   public:
    int x2;
    int y2;
    int t;
    Info(int c, int d, int k) {
        x2 = c;
        y2 = d;
        t = k;
    }
};
int w, h, g, e, arr[31][31], dist[31][31];
vector<Info> ghost_holes[31][31];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        // dist 배열 초기화
        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++) dist[i][j] = INF;
        // arr 배열 초기화
        for (int i = 0; i < 31; i++)
            for (int j = 0; j < 31; j++) arr[i][j] = 0;
        // ghost_holes 초기화
        for (int i = 0; i < 31; i++)
            for (int j = 0; j < 31; j++) ghost_holes[i][j].clear();

        cin >> g;
        for (int i = 0; i < g; i++) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = TOMB;
        }
        cin >> e;
        for (int i = 0; i < e; i++) {
            int x1, y1, x2, y2, t;
            cin >> x1 >> y1 >> x2 >> y2 >> t;
            ghost_holes[x1][y1].push_back(Info(x2, y2, t));
        }
        bool is_cycle = false;
        dist[0][0] = 0;
        // w * h - 1번 루프로 모두 갱신하고 마지막에 음의 사이클 파악
        for (int k = 0; k < w * h; k++) {
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < h; j++) {
                    if (i == w - 1 && j == h - 1)
                        continue;  // 마지막에 도달하면 끝
                    if (dist[i][j] == INF || arr[i][j] == TOMB) continue;
                    // ghost holes
                    for (int d = 0; d < ghost_holes[i][j].size(); d++) {
                        int ny = ghost_holes[i][j][d].x2;
                        int nx = ghost_holes[i][j][d].y2;
                        int next_cost = ghost_holes[i][j][d].t;
                        if (dist[ny][nx] > dist[i][j] + next_cost) {
                            dist[ny][nx] = dist[i][j] + next_cost;
                            if (k == w * h - 1) is_cycle = true;
                        }
                    }
                    if (ghost_holes[i][j].size() > 0) continue;
                    // 상하좌우
                    for (int d = 0; d < 4; d++) {
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        int next_cost = 1;  // i, j에서 한 칸 이동하므로
                        if (ny < 0 || nx < 0 || ny >= w || nx >= h ||
                            arr[ny][nx] == TOMB)
                            continue;
                        if (dist[ny][nx] > dist[i][j] + next_cost) {
                            dist[ny][nx] = dist[i][j] + next_cost;
                            if (k == w * h - 1) is_cycle = true;
                        }
                    }
                }
            }
        }
        if (is_cycle) {
            cout << "Never"
                 << "\n";
        } else if (dist[w - 1][h - 1] == INF) {
            cout << "Impossible"
                 << "\n";
        } else {
            cout << dist[w - 1][h - 1] << "\n";
        }
    }
    return 0;
}
