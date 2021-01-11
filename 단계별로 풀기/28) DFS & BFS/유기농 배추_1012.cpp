#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset 사용 위해
using namespace std;
#define MAX 50 + 1

int t;
int m, n, k;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int cnt = 0;


void dfs(int a, int b) {
	if (arr[a][b] == 0) // 해당 자리가 0이면 그냥 리턴
		return;
	visited[a][b] = true; // 해당 자리 왔다 갔음을 표시
	cnt++; // 수 카운트
	// 상
	if (visited[a - 1][b] != true && arr[a - 1][b] == 1) {
		dfs(a - 1, b); // 다음의 dfs를 진행
		arr[a - 1][b] = 0; // 이미 조사한 자리는 0으로 만들어버림
	}
	// 하
	if (visited[a + 1][b] != true && arr[a + 1][b] == 1) {
		dfs(a + 1, b);
		arr[a + 1][b] = 0;
	}
	// 좌
	if (visited[a][b - 1] != true && arr[a][b - 1] == 1) {
		dfs(a, b - 1);
		arr[a][b - 1] = 0;
	}
	// 우
	if (visited[a][b + 1] != true && arr[a][b + 1] == 1) {
		dfs(a, b + 1);
		arr[a][b + 1] = 0;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> t;
	while (t-- > 0) {
		cin >> m >> n >> k; // [n][m]이다.

		// 모든 배열을 초기화
		memset(arr, 0, sizeof(arr)); 
		memset(visited, false, sizeof(visited));

		int tmp1, tmp2;
		while (k-- > 0) {
			cin >> tmp1 >> tmp2;
			arr[tmp2 + 1][tmp1 + 1] = 1; // 편의를 위해 1,1부터 시작하도록
		}
		int ans = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cnt = 0; // 매번 cnt를 0으로 초기화
				dfs(i, j); // 모든 경우에 대해서 dfs 진행
				if (cnt != 0)
					ans++;
			}
		}
		cout << ans << "\n";
	}
}