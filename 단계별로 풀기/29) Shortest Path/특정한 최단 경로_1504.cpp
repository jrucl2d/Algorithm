#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 다익스트라 알고리즘 사용
// 두 정점 m1, m2를 무조건 지나야 하므로 1-m1-m2-n과 1-m2-m1-n 둘 중 하나가 답

#define MAX 800 + 1
#define INF 10000000
int n, e;
int m1, m2; // must1, must2. 무조건 거쳐야 하는 두 정점

vector<pair<int, int>>arr[MAX]; // arr[현재]에 이어진 {다음 정점까지의 거리, 다음 정점}
int dist[MAX]; // 해당 index 정점까지 축적된 거리를 저장할 배열

int func(int start, int end) {
	for (int i = 0; i <= n; i++) // dist의 모든 요소를 무한대로 초기화
		dist[i] = INF;
	dist[start] = 0; // 처음 시작점은 축적된 거리가 0
	priority_queue<pair<int, int>>pq; // {정점의 거리, 정점}으로 이루어진 우선순위 큐(최대 힙)
	pq.push({ 0, start }); // 시작 정점은 거리가 0이고 정점은 해당 시작 정점이다.

	while (!pq.empty()) {
		// 우선순위 큐는 최대 힙인데, 최소 거리를 구해야 하므로 뒤의 코드에서 큐에 넣을 때 -를 붙여서 넣는다.
		// 따라서 뺄 때도 -를 넣어서 빼야 한다.
		int beforeval = -pq.top().first; // 현재의 거리 값
		int beforeloc = pq.top().second; // 현재의 위치
		pq.pop(); // 값을 변수에 저장했으므로 큐에서 뺀다.

		for (int i = 0; i < arr[beforeloc].size(); i++) { // 이전 loc에 연결된 모든 정점들에 대해서
			int nextval = arr[beforeloc][i].first; // 다음 정점까지의 거리
			int nextloc = arr[beforeloc][i].second; // 다음 정점

			// 다음 정점 까지의 길이(처음이라 INF든지, 한 번 구했어서 어떤 값을 가졌든지)가
			// 현재 정점까지의 길이에 현재 정점에서 다음 정점까지의 거리를 더한 값보다 작으면 치환 
			if (dist[nextloc] > beforeval + nextval) {
				dist[nextloc] = beforeval + nextval;
				pq.push({ -dist[nextloc], nextloc });
			}
		}
	}
	if (dist[end] == INF) // 만약 start에서 end까지의 이어진 길이 없다면 초기값 INF가 출력
		return -1;
	else return dist[end]; // 값이 존재하면 그 최소값 출력
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> e; 

	int a, b, c; // a와 b가 이어져있고, 거리는 c
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr[a].push_back({ c, b });
		arr[b].push_back({ c, a });
	}
	cin >> m1 >> m2;
	int one1 = func(1, m1); // 1-m1-m2-n의 경우
	int one2 = func(m1, m2);
	int one3 = func(m2, n);
	bool one = true;
	if (one1 == -1 || one2 == -1 || one3 == -1) // 도중에 길이 없으면 표시
		one = false;
	int two1 = func(1, m2); // 1-m2-m1-n의 경우
	int two2 = func(m2, m1);
	int two3 = func(m1, n);
	bool two = true;
	if (two1 == -1 || two2 == -1 || two3 == -1) // 도중에 길이 없으면 표시
		two = false;
	if (!one && !two) // 아예 길이 없으면 -1
		cout << -1;
	else if (one && !two) // 둘 중 길이 존재하는 것 출력
		cout << one1 + one2 + one3;
	else if (!one && two)
		cout << two1 + two2 + two3;
	else cout << min(one1 + one2 + one3, two1 + two2 + two3); // 둘 다 존재하면 가장 짧은 것 출력
}
