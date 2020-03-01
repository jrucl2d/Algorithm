#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>
using namespace std;
int t, airport, money, ticket;
#define MAX 100 + 1
#define INF 10000000
typedef tuple<int, int, int> tupe;

int dp[MAX][10000 + 1]; // 1번 노드에서 i번 노드까지 j의 비용으로 갔을 때의 최소 시간 저장

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> t;
	while (t-- > 0) {
		vector<tupe>arr[MAX]; // 기존에 다익스트라에서 vector 안에 pair이 들어갔던 것처럼

		cin >> airport >> money >> ticket;
		int depart, arrive, cost, time;
		for (int i = 0; i < ticket; i++) {
			cin >> depart >> arrive >> cost >> time;
			arr[depart].push_back({ arrive, cost, time });
		}
		// dp 초기화
		for (int i = 1; i <= airport; i++)
			for (int j = 0; j <= money; j++)
				dp[i][j] = INF;
		dp[1][0] = 0; // 첫 번째 시작점은 0의 비용으로 0시간이 걸린다.

		priority_queue<tupe, vector<tupe>, greater<tupe>>pq; // {시간, 가격, 다음 공항}, 내림차순(최소 힙)
		pq.push({ 0,0,1 }); // 첫 번째 시작점은 비용, 시간이 0이다.

		bool exit = false;
		while (!pq.empty()) {
			int beforeTime = get<0>(pq.top()); // 시간
			int beforeCost = get<1>(pq.top()); // 가격
			int beforeTo = get<2>(pq.top()); // 다음 공항
			pq.pop();
			if (beforeTo == airport) { // 주어진 cost에서 time이 작은 순으로 나열되어 있기 때문에 도착하는 순간 바로 출력하면 됨
				cout << beforeTime << "\n";
				exit = true;
				break;
			}
			// 이미 dp에 저장된대로 beforeTo 노드까지 오는 시간이 새로 고려한 시간보다 더 빠른 경우 생략 가능하다.
			if (dp[beforeTo][beforeCost] < beforeTime)
				continue;

			for (int i = 0; i < arr[beforeTo].size(); i++) { // 지금 beforeTo 노드에 연결된 모든 노드에 대해서
				int nextTime = get<2>(arr[beforeTo][i]);
				int nextCost = get<1>(arr[beforeTo][i]);
				int nextTo = get<0>(arr[beforeTo][i]);

				if (beforeCost + nextCost > money) continue; // 예산을 초과해버리면

				// 만약 다음 노드까지 (이전 노드까지의 비용 + 이전 노드에서 다음 노드 가는 데 드는 비용)으로 갔을 때 드는 시간이(기존 정보)
				// 이전까지의 시간에 지금 시간을 더한 시간(새로운 시간)보다 짧으면 ==> 기존 정보가 더 좋으면 그냥 생략
				if (dp[nextTo][beforeCost + nextCost] <= beforeTime + nextTime) continue;

				// 모든 생략 조건에 해당 없으면 힙에도, dp에도 값을 갱신
				pq.push({beforeTime + nextTime, beforeCost + nextCost, nextTo });
				dp[nextTo][beforeCost + nextCost] = beforeTime + nextTime;
			}
		}
		if (!exit)
			cout << "Poor KCM\n";
	}
}