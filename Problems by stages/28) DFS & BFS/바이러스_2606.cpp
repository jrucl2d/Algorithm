#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100 + 1

int n, m, v;
int arr[MAX][MAX];
bool visited[MAX];
int cnt = 0;

void dfs(int start) {
	visited[start] = true; // dfs에 들어오면 방문한 것이다.
	cnt++;

	for (int i = 1; i <= n; i++) {
		// 이미 방문한 곳(visited[i]=true)이거나 간선이 없는 경우(arr[start]=1)은 건너뜀
		if (visited[i] == true || arr[start][i] == 0)
			continue;
		dfs(i);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		arr[a][b] = 1; arr[b][a] = 1;
	}
	dfs(1); // 1번 컴퓨터가 바이러스에 걸렸을 경우 연결된 컴퓨터 수 - 1(1번 컴퓨터 자신)
	cout << cnt - 1;
}