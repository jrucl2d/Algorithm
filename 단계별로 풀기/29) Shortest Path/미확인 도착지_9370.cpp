#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 50000 + 1
#define INF 10000000

// 다익스트라 사용
// 원래 start-must1-must2-end와 start-must2-must1-end 중 하나와 start-end가 같다면 end 후보지로 적합함을 알 수 있다. 
// 그러나 이 방법은 각 후보지에 대해서 다익스트라를 세 번 사용한다. 
// 멋진 풀이 : 모든 간선 가중치(거리 값)을 두 배로 해주고, must1-must2의 값을 -1 해준다. 
// 그러면 후보지들의 다익스트라 결과값 중에서 홀수가 나온 경우는 must1-must2를 지난 후보라고 볼 수 있으므로 다익스트라를 한 번 사용한다.

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	int t; // 테스트 케이스 수
	cin >> t;

	while (t-- > 0) {
		
		int inter, road, goal; // 각각 교차로, 목적지, 후보
		int start, must1, must2; // 각각 출발지, 반드시 지나야 하는 후보 두 개 

		vector<int>ans; // 답을 저장
		vector<pair<int, int>> arr[MAX]; // arr[시작정점]에서 {다음 정점까지의 거리, 다음정점}
		int dist[MAX]; // 해당 인덱스 정점까지 누적된 거리 값
		vector<int>possible; // 도착 후보지

		cin >> inter >> road >> goal;
		cin >> start >> must1 >> must2;
		int a, b, d;
		for (int i = 0; i < road; i++) {
			cin >> a >> b >> d;
			d *= 2; // 모든 거리 가중치를 두 배 한다.
			if ((a == must1 && b == must2) || (a == must2 && b == must1)) // must1-must2의 가중치는 추가로 -1 해준다.
				d -= 1;
			arr[a].push_back({ d,b }); // 양방향 도로이므로
			arr[b].push_back({ d,a });
		}
		int x;
		for (int i = 0; i < goal; i++) {
			cin >> x;
			possible.push_back(x); // 후보지 저장
		}
		// 여기서부터 다익스트라 알고리즘
		for (int j = 0; j < goal; j++) { // 모든 후보지들에 대해서
			priority_queue<pair<int, int>>pq; // {거리값, 정점}

			for (int i = 0; i <= inter; i++) // 모든 거리값 INF로 초기화
				dist[i] = INF;
			dist[start] = 0; // 출발 지점까지의 거리는 0
			pq.push({ 0, start }); // 출발지 큐에 넣음

			while (!pq.empty()) {
				// 최소 거리를 구해야 하므로 넣을 때 -로 넣고 뺄 때도 -로 뺀다.
				int beforeval = -pq.top().first; // 현재 정점의 거리 가중치
				int beforeloc = pq.top().second; // 현재 정점
				pq.pop();

				for (int i = 0; i < arr[beforeloc].size(); i++) { // 현재 정점에 연결된 모든 정점에 대해서
					int nextval = arr[beforeloc][i].first;
					int nextloc = arr[beforeloc][i].second;

					if (dist[nextloc] > beforeval + nextval) {
						dist[nextloc] = beforeval + nextval;
						pq.push({ -dist[nextloc], nextloc }); // 넣을 때 -로 넣음
					}
				}
			}
			if (dist[possible[j]] % 2 == 1 && dist[possible[j]] != INF) // 결과가 만약 홀수이면 답에 넣음
				ans.push_back(possible[j]);
			sort(ans.begin(), ans.end()); // 오름차순 정렬
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
}
