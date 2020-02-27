#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

// 벨만 포드 알고리즘 사용 <- 다익스트라와는 다르게 음의 가중치 계산이 가능
// 1. 최단 경로는 사이클을 포함하면 안 되므로 최대 |v| - 1개의 간선만 사용 가능
// 2. 최단 거리가 업데이트되는 노드가 없어질 때까지 반복해서 계산. 
// 3. 음의 가중치 때문에 업데이트가 무한정 반복되면 탈출(무한 반복시 최단거리 없다고 봄)
// 방문하지 않은 정점(현재 시점에서 값이 무한대)에서 출발하는 edge는 고려하지 않는다. 무한대에서 가중치 더해도 무한대이므로
// 모든 노드 n개에 대해서 다익스트라 알고리즘을 적용하는 것과 같으므로 O(N^3)의 시간복잡도
// 벨만 포드를 두 번째 계산했을 때 값이 바뀌는 경우는 음의 간선이 순환구조로 되어있어 
// 최단 경로 계산에 영향을 준다는 것이므로 이럴 경우는 최단 경로가 없다고 보면 된다.

#define MAX 500 + 1 
#define INF 10000000
int dist[MAX]; // 해당 정점에서의 누적 거리 가중치
vector<pair<int,int>> arr[MAX]; // arr[시작점]에서 {다음 정점, 다음 정점까지의 간선 가중치}
int n, m; // 순서대로 정점, 간선의 개수

int func(int howmanytimes) { // howmaytimes 파라미터로 몇 번째 수행중인지 파악(처음에 0)
	int changed = 0; // 값이 바뀌었는지 여부

	for (int i = 1; i <= n; i++) { // 모든 정점에서 출발해서 한 번씩 다익스트라 반복
		for (int j = 1; j <= n; j++) { // 모든 정점에 대해서
			for (int k = 0; k < arr[j].size(); k++) { // 그 정점에 연결된 모든 노드들을

				// 현재 노드에서 다음 노드로 가는 가중치. 새로 계산해본 가중치 값
				// 현재 노드까지의 가중치 합계 값에서 다음 노드까지의 간선 가중치를 더한다.
				int newval = dist[j] + arr[j][k].second;

				// 기존에 이미 저장되어 있던 해당 다음 노드의 원래 가중치 누적 값
				// j번째 노드에서 k번째에 연결된 노드 위치(arr[j][k].first)의 dist값(처음엔 아마 무한대)
				int beforeval = dist[arr[j][k].first];

				// 만약 현재 노드가 무한대이면 무한대에서 가중치 더해봐야 무한대이므로 의미 없다. 고로 생략
				// 만약 새로 구한 (현재 노드-다음 노드)연결의 가중치가 기존값보다 더 작으면 교체
				if (dist[j] != INF && newval < beforeval) {
					changed = 1; // 값이 바뀌었다.
					// 만약 두 번째 실행에서 값이 바뀌면 1을 리턴하고, 이 말은 음의 순환이 존재, 즉 최단 경로가 없다는 뜻
					// 처음 변환이라면 값이 변해서 changed가 1이어도 howmanytimes가 0이므로 문제 없다.
					if (changed * howmanytimes != 0)
						return changed;
					dist[arr[j][k].first] = newval; // 그렇지 않으면 값을 교체
				}
			}
		}
	}
	return changed; // 처음 변환했거나 두 번째 계산에도 값 변동이 없으면 0이 리턴. 문제가 있다면 여기까지 못 옴
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[a].push_back({ b, c });
	}
	for (int i = 2; i <= n; i++) 
		dist[i] = INF; // 처음에 가중치 모두 무한대로 초기화
	dist[1] = 0; // 문제에서 주어진 시작점 1번은 거리 가중치 0으로 초기화

	func(0); // 최초 실행. howmanytimes 변수에 0이 들어가므로 0이 리턴될 것이다.

	if (func(1) != 0)  // 두 번째 실행. 만약 값이 0 이외의 값이 리턴되면 최단 경로가 없다.
		cout << -1;
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) // 해당 경로의 길이 없다면 아마 dist값이 변동 없이 초기값 INF일 것이다.
				cout << -1 << "\n";
			else cout << dist[i] << "\n"; // 아니면 dist값 출력
		}
	}
}