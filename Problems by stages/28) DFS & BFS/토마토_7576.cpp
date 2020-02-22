#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000 + 1

int n, m;
int arr[MAX][MAX];
int visited[MAX][MAX]; // 지나온 길이 저장
queue<pair<int, int>>q;

// 방향
int lr[4] = { -1,0,1,0 };
int ud[4] = { 0,1,0,-1 };

void bfs(int a, int b) {
	while (!q.empty()) { // 큐가 비지 않는 한
		a = q.front().first;
		b = q.front().second;
		q.pop(); // 최초값 빼내기

		for (int i = 0; i < 4; i++) { // 상하좌우 네방향 탐색
			int na = a + lr[i];
			int nb = b + ud[i];
			if (1 <= na && na <= n && 1 <= nb && nb <= m) { // 범위 내에서
				// 아직 안 간 길이고, 해당 위치에 익지 않은 토마토가 있으면
				if (visited[na][nb] == -1 && arr[na][nb] == 0) {
					q.push({ na, nb }); // 해당 위치 큐에 넣고
					visited[na][nb] = visited[a][b] + 1; // 날짜 하나 증가
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			visited[i][j] = -1; // 방문했는지 여부의 초기값 모두 -1로 설정(날짜)
			if (arr[i][j] == 1) { // 이미 익어있는 토마토는
				q.push({ i,j }); // 큐에 넣고
				visited[i][j] = 0; // 방문했다고 표시(첫날)
			}
		}
	}
	bfs(1, 1);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(ans, visited[i][j]); // 날짜 중에서 최대값이 바로 토마토가 모두 익는 최소 날짜
			if (visited[i][j] == -1 && arr[i][j] == 0) { // 근데 만약 방문 안 한 안 익은 토마토가 남아있으면
				cout << -1; return 0; // -1 출력 후 종료
			}
		}
	}
	cout << ans;
}