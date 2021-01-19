#include <iostream>
#include <vector>
using namespace std;

int v, e, cnt = 0, visit_order = 1;
vector<int> adj[10010];
bool ans[10010]; // 단절점
int order[10010]; // 방문 순서

int dfs(int parent, int index, bool is_root) { // 사이클이 존재하므로 부모를 또 만나게 된다.
	int child_num = 0; // 자식의 수(연결된 간선의 수가 아님! 덩어리 기준)
	order[index] = visit_order; // 현재의 방문 순서를 저장
	int min_visit_order = visit_order; // 내 자식들이 만날 수 있는 점 중 가장 작은 점

	visit_order += 1;
	for (int i = 0; i < adj[index].size(); i++) {
		int nextIndex = adj[index][i];
		if (nextIndex == parent) continue; // 부모를 만나지는 않음(역방향 방지)
		if (order[nextIndex]) { // 이미 방문한 노드의 경우
			// 나에게 필요한 값이 아니다. 아래의 새로 방문한 경우의 노드들이 중요하다.
			min_visit_order = min(min_visit_order, order[nextIndex]);
		}
		else { // 새로 방문하는 경우
			int tmp = dfs(index, nextIndex, false);
			min_visit_order = min(min_visit_order, tmp);
			if (!is_root && tmp >= order[index]) {
				ans[index] = true;
			}
			child_num += 1;
		}
	}
	if (adj[index].size() == 1) return order[index]; // 리프노드이면 단절점 처리를 안 해줌
	// 예외 -> 루트일 경우, 자식이 두 개 이상이면 단절점
	if (is_root) {
		if (child_num >= 2) {
			ans[index] = true;
		}
	}

	return min(min_visit_order, order[index]); // 내가 만난 점 중 방문 순서 가장 작은 점 반환
}

int main() {
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		if (order[i] == 0) {
			dfs(0, i, true); // 그래프가 모두 하나로 연결되어있지 않을 수 있다. 
		}
	}
	for (int i = 1; i <= v; i++) {
		if (ans[i]) cnt += 1;
	}
	cout << cnt << "\n";
	for (int i = 1; i <= v; i++) {
		if (ans[i]) {
			cout << i << " ";
		}
	}

	return 0;
}