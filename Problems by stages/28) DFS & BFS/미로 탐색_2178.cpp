#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define MAX 100 + 1

int n, m;
int arr[MAX][MAX];
int visited[MAX][MAX]; // 지나온 길이 저장

void bfs(int a, int b) {
	queue<pair<int,int>>q;
	q.push({ a,b });
	visited[a][b] = 1; // 처음(1,1)은 거리 1
	// 방향
	int lr[4] = { -1,0,1,0 };
	int ud[4] = { 0,1,0,-1 };

	while (!q.empty()) { // 큐가 비지 않는 한

		a = q.front().first;
		b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) { // 상하좌우 네방향 탐색
			int na = a + lr[i];
			int nb = b + ud[i];
			if (1 <= na && na <= n && 1 <= nb && nb <= m) { // 범위 내에서
				// 아직 안 간 길이고, 해당 위치에 길이 있으면
				if (visited[na][nb] == 0 && arr[na][nb] == 1) {
					q.push({ na, nb }); // 해당 위치 큐에 넣고
					visited[na][nb] = visited[a][b] + 1; // 온 거리 하나 증가
				}
				else if (visited[na][nb] == 0) // 안 간 길이긴 한데 길이 없으면
					visited[na][nb] = -1; // -1로 초기화
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++)
			arr[i][j] = s[j - 1] - '0';
	}

	bfs(1, 1);
	cout << visited[n][m];
}