#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 500 + 1
int dp[MAX][MAX]; // 내리막을 통해 i,j 위치까지 오는 최대 경우의 수
int arr[MAX][MAX];
int m, n;

int dir[4][2] = { {-1,0}, {0,-1}, {1,0} , {0,1} }; // 상하좌우 방향

// DFS + DP의 풀이. 
int func(int y, int x) {
	if (y == m && x == n) return 1; // 기저사례, 끝에 도달하면 경로의 수 1을 리턴하고 탈출
	int& tmp = dp[y][x]; // dp 값을 변수에 저장
	if (tmp != -1) return tmp; // 값이 -1이 아니면(값이 존재하면) 리턴(-1로 초기화되어 있으므로)
	
	// 아래부터는 dp의 값이 -1인 경우, 즉 경로의 수가 계산된 적 없고 방문한 적이 없는 경우. 계산이 필요한 부분이다.
	tmp = 0; // 해당 위치를 움직였기 때문에 0으로 만들어줌(가지 않은 -1과 차별화)
	for (int i = 0; i < 4; i++) { // 반복문을 통해 if문을 상하좌우에 대해 4번 사용하는 것을 
		int nexty = y + dir[i][1]; // 상, 하(행)
		int nextx = x + dir[i][0]; // 좌, 우(열)

		// dp의 범위 내에서 내리막길일 경우
		if (m >= nexty && nexty > 0 && n >= nextx && nextx > 0) {
			if (arr[nexty][nextx] < arr[y][x])
				tmp += func(nexty, nextx); // 다음 위치의 dp값을 더해준다.
		}
	}
	return tmp; // 해당 위치에서의 dp값 리턴
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1; // dp값을 모두 -1로 초기화
		}
	}
	cout << func(1, 1);
}
