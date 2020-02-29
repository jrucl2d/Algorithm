#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 10000000
#define MAX 100 + 1

// 플로이드 워셜 알고리즘 사용
// 다익스트라 알고리즘은 하나의 정점에서 모든 정점까지의 최단거리를 구하는 알고리즘이었고, 
// 플로이드 워셜 알고리즘은 모든 정점에서 모든 정점으로의 최단거리를 구하는 알고리즘이다.
// 거쳐가는 정점을 기준으로 알고리즘을 수행한다.

int n, m; // 정점, 간선
int arr[MAX][MAX];
int darr[MAX][MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (arr[a][b] > 0 && arr[a][b] > c) // a에서 b로 가는 경로가 여러 경우가 있을 수 있으므로 더 짧으면 갱신
			arr[a][b] = c; // a에서 b로 가는 비용 c
		else if (arr[a][b] == 0) arr[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != 0)
				darr[i][j] = arr[i][j];
			else darr[i][j] = INF;
			if (i == j) darr[i][j] = 0; // 자기 자신이 출발이자 도착인 경우는 거리가 0
		}
	}

	for (int k = 1; k <= n; k++) { // 거쳐가는 점 k에 대해서
		for (int i = 1; i <= n; i++) { // 시작 점 i
			for (int j = 1; j <= n; j++) { // 도착 점 j
				 // 거쳐가는 점 k에서 출발하거나 도착하는 경로, 자기 자신이 출발이자 도착인 경로 제외
				if (i == j || i == k || j == k) continue;
				// 만약 거쳐가는 경로가 더 짧으면 갱신
				if (darr[i][j] > darr[i][k] + darr[k][j])
					darr[i][j] = darr[i][k] + darr[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (darr[i][j] == INF)
				cout << 0 << " ";
			else cout << darr[i][j] << " ";
		}
		cout << "\n";
	}
}