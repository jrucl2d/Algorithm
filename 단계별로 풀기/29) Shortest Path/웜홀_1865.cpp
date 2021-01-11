#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 500 + 1
#define INF 10000000

int tc;
int n, m, w;
vector<pair<int, int>>*arr; // arr[시작정점] {다음 정점, 가중치}
int *dist; // 거리 가중치 누적 저장

int func(int cnt) {
	int changed = 0;

	for (int i = 1; i <= n; i++) { // 정점 개수 만큼 반복
		for (int j = 1; j <= n; j++) { // j 인덱스 시점의 정점에 대해서
			for (int k = 0; k < arr[j].size(); k++) { // 그 정점에 연결된 모든 노드들에 대해서
				int newval = dist[j] + arr[j][k].second; // 현재 정점의 가중치 누적 + 거기 연결된 k의 가중치(새로운 값)
				int beforeval = dist[arr[j][k].first]; // 그냥 j에 연결된 k에 저장되 있던 가중치 누적값(기존 값)

				if (dist[j] != INF && newval < beforeval) { // j가 INF이면 가중치 더해도 어차피 INF라 무의미. 만약 새 값이 더 작으면
					changed = 1;
					if (changed * cnt != 0) // 처음 실행이면 cnt가 0이므로 문제 없음. 두 번째 실행이면 1이라서 만약 또 변경되면 루프 존재
						return changed;
					dist[arr[j][k].first] = newval; // 위의 것 해당 없으면 새로운 값 대입
				}
			}
		}
	}
	return changed;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> tc;
	while (tc-- > 0) {

		arr = new vector<pair<int, int>>[MAX];
		dist = new int[MAX];

		cin >> n >> m >> w;
		int s, e, t;
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			arr[s].push_back({ e, t }); // 양방향 도로
			arr[e].push_back({ s, t });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			arr[s].push_back({ e, -t }); // 웜홀은 단방향이고, t만큼 줄어들기 때문에 -가중치
		}

		for (int i = 2; i <= n; i++) // 가중치 누적값 INF로 초기화
			dist[i] = INF;
		dist[1] = 0; // 시작점은 가중치 0

		func(0); // 첫 실행으로 최소 값 찾음
		if (func(1) != 0) // 루프가 존재하면 0 이외의 값이 리턴됨
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
		delete[]arr;
		delete[]dist;
	}
}