#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000
#define MAX 400 + 1
int v, e;
int arr[MAX][MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> v >> e;
	for (int i = 0; i < MAX; i++) { // 모든 값을 INF로 초기화
		for (int j = 0; j < MAX; j++) {
			arr[i][j] = INF;
		}
	}

	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr[a][b] = c; // a에서 b로 가는 비용이 c
	}

	for (int k = 1; k <= v; k++) { // 거쳐가는 점 k
		for (int i = 1; i <= v; i++) { // 시작점 i
			for (int j = 1; j <= v; j++) { // 도착점 j
				// 만약 거쳐가는 경로가 더 짧으면 갱신
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= v; i++) { // 자기 자신으로 가는 모든 경우에 대해서
		ans = min(ans, arr[i][i]);
	}
	if (ans != INF)
		cout << ans;
	else cout << -1;
}