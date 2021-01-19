#include <iostream>
#include <vector>
using namespace std;

int v, e, cnt = 0, visit_order = 1;
vector<int> adj[10010];
bool ans[10010]; // ������
int order[10010]; // �湮 ����

int dfs(int parent, int index, bool is_root) { // ����Ŭ�� �����ϹǷ� �θ� �� ������ �ȴ�.
	int child_num = 0; // �ڽ��� ��(����� ������ ���� �ƴ�! ��� ����)
	order[index] = visit_order; // ������ �湮 ������ ����
	int min_visit_order = visit_order; // �� �ڽĵ��� ���� �� �ִ� �� �� ���� ���� ��

	visit_order += 1;
	for (int i = 0; i < adj[index].size(); i++) {
		int nextIndex = adj[index][i];
		if (nextIndex == parent) continue; // �θ� �������� ����(������ ����)
		if (order[nextIndex]) { // �̹� �湮�� ����� ���
			// ������ �ʿ��� ���� �ƴϴ�. �Ʒ��� ���� �湮�� ����� ������ �߿��ϴ�.
			min_visit_order = min(min_visit_order, order[nextIndex]);
		}
		else { // ���� �湮�ϴ� ���
			int tmp = dfs(index, nextIndex, false);
			min_visit_order = min(min_visit_order, tmp);
			if (!is_root && tmp >= order[index]) {
				ans[index] = true;
			}
			child_num += 1;
		}
	}
	if (adj[index].size() == 1) return order[index]; // ��������̸� ������ ó���� �� ����
	// ���� -> ��Ʈ�� ���, �ڽ��� �� �� �̻��̸� ������
	if (is_root) {
		if (child_num >= 2) {
			ans[index] = true;
		}
	}

	return min(min_visit_order, order[index]); // ���� ���� �� �� �湮 ���� ���� ���� �� ��ȯ
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
			dfs(0, i, true); // �׷����� ��� �ϳ��� ����Ǿ����� ���� �� �ִ�. 
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