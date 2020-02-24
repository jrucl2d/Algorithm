#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000 // 적당히 큰 수

// 다익스트라 알고리즘(Dijkstra Algorithm) : 현재까지 알고 있던 최단 경로를 계속해서 갱신
// 1. 출발노드 설정
// 2. 출발노드를 기점으로 각 노드의 최소 비용 저장
// 3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드 선택
// 4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려해서 최소 비용 갱신
// 우선순위 큐(힙)을 이용해서 O(nlogn)의 시간복잡도 내에 해결 가능
int v, e, k;
vector<pair<int, int>>* arr; // 거리 값, 해당 시작점에서 이어진 정점
priority_queue <pair<int, int>>pq; // {값, 정점}으로 이루어진 값을 갖는 우선순위 큐(힙)
int *dist; // 거리를 저장할 벡터

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> v >> e >> k; // 정점, 간선, 시작 정점

	arr = new vector<pair<int, int>>[v + 1]; // 정점이 1부터 시작하므로 v+1개의 벡터 동적할당

	int from, to, val; // 입력받을 요소
	for (int i = 0; i < e; i++) {
		cin >> from >> to >> val;
		arr[from].push_back({ val, to }); // 거리 값, 해당 시작점에서 이어진 정점 순으로 벡터에 push해준다.
	}
	dist = new int[v + 1];
	for (int i = 1; i <= v; i++)
		dist[i] = INF; // 초기 거리를 다 무한대로 설정
	dist[k] = 0; // 시작 지점은 거리가 0이다.
	pq.push({ 0, k }); // 힙에 시작점 넣어준다.

	while (!pq.empty()) {
		int beforeval = -pq.top().first; // 현재까지의 거리 값. 우선순위 큐는 최대 힙이므로 최소 거리순으로 정렬 위해 - 붙임
		int beforeloc = pq.top().second; // 현재의 노드 위치(정점)
		pq.pop();
		
		for (int i = 0; i < arr[beforeloc].size(); i++) { // 현재 정점에 연결된 모든 노드에 대해서
			int nextval = arr[beforeloc][i].first; // 현재 노드에서 이어진 i번째 노드의 거리 값
			int nextloc = arr[beforeloc][i].second; // 현재 노드에서 이어진 i번재 노드의 위치(정점)

			if (dist[nextloc] > dist[beforeloc] + nextval) {
				dist[nextloc] = dist[beforeloc] + nextval;
				pq.push({ -dist[nextloc], nextloc }); // 다음 노드의 정보를 우선순위 큐에 넣어줌
			}	
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			cout << "INF" << "\n";
		else if (i == k)
			cout << 0 << "\n";
		else
			cout << dist[i]<<"\n";
	}
}