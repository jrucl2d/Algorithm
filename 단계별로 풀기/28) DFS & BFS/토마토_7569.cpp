#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100 + 1

int n, m, h; // 7576번 문제에서 삼차원으로 바뀐 문제
int arr[MAX][MAX][MAX];
int visited[MAX][MAX][MAX]; // 지나온 길이 저장
struct in {
	int x;
	int y;
	int z;
};
queue<in>q;

// 방향
int dx[6] = { -1, 0, 0, 1, 0, 0 };
int dy[6] = { 0, -1, 0, 0, 1, 0 };
int dz[6] = { 0, 0, -1, 0, 0, 1 };

void bfs(int a, int b, int c) {
	while (!q.empty()) { // 큐가 비지 않는 한
		a = q.front().x;
		b = q.front().y;
		c = q.front().z;

		q.pop(); // 최초값 빼내기

		for (int i = 0; i < 6; i++) { // 상하좌우 여섯 방향 탐색
			int na = a + dx[i];
			int nb = b + dy[i];
			int nc = c + dz[i];

			if (1 <= na && na <= n && 1 <= nb && nb <= m && 1 <= nc && nc <= h) { // 범위 내에서
				// 아직 안 간 길이고, 해당 위치에 익지 않은 토마토가 있으면
				if (visited[na][nb][nc] == -1 && arr[na][nb][nc] == 0) {
					q.push({ na, nb, nc }); // 해당 위치 큐에 넣고
					visited[na][nb][nc] = visited[a][b][c] + 1; // 날짜 하나 증가
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> m >> n >> h;
	for (int k = 1; k <= h; k++) { // z축을 먼저 받아야 함
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j][k];
				visited[i][j][k] = -1; // 방문했는지 여부의 초기값 모두 -1로 설정(날짜)
				if (arr[i][j][k] == 1) { // 이미 익어있는 토마토는
					q.push({ i,j,k }); // 큐에 넣고
					visited[i][j][k] = 0; // 방문했다고 표시(첫날)
				}
			}
			
		}
	}
	bfs(1, 1, 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= h; k++) {
				ans = max(ans, visited[i][j][k]); // 날짜 중에서 최대값이 바로 토마토가 모두 익는 최소 날짜
				if (visited[i][j][k] == -1 && arr[i][j][k] == 0) { // 근데 만약 방문 안 한 안 익은 토마토가 남아있으면
					cout << -1; return 0; // -1 출력 후 종료
				}
			}
		}
	}
	cout << ans;
}