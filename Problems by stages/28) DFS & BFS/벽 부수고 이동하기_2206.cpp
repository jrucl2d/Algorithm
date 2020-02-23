#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define MAX 1000 + 1
struct in {
	int first;
	int second;
	int flag;
};
int arr[MAX][MAX];
int visited[MAX][MAX][2]; // 마지막에 벽을 뚫었는지 여부를 나타낼 flag 하나 추가
int n, m;

int bfs(int a, int b) {
	queue<in>q;
	q.push({ a, b, 0 });
	visited[a][b][0] = 1; // 시작 지점 포함, 아직 벽 안 뚫음

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int c = 0; // 벽 뚫었는지 여부 저장할 변수

	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		c = q.front().flag;

		q.pop();
		if (a == n && b == m) // 도착지점에 도달하면 리턴
			return visited[a][b][c];

		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (1 <= na && na <= n && 1 <= nb && nb <= m) {
				if (visited[na][nb][c] == 0 && arr[na][nb] == 0) { // 기본적으로 길이 있는데, 아직 안 갔으면
					q.push({ na,nb,c });
					visited[na][nb][c] = visited[a][b][c] + 1;
				}
				if (arr[na][nb] == 1 && c == 0) { // 만약 벽이 있는데, 아직 안 뚫었다면
					visited[na][nb][1] = visited[a][b][c] + 1; // 뚫기 전 것에 1을 더한다.
					q.push({ na, nb, 1 }); // 뚫은 이후의 경우를 큐에 추가한다.(여기서 파생되면 c가 1인 채로 진행된다.)
				}
			}
		}
	}
	return -1; // 만약 n, m까지 못 가고 큐가 비어버리면(값이 안 나오게 되면) -1 출력
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
	cout << bfs(1, 1);
}