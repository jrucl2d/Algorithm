#include <iostream>

using namespace std;
int n, m;
int parent[1000001];

int find_parent(int a) {
	if (a == parent[a]) return a;
	parent[a] = find_parent(parent[a]);
	return parent[a];
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	parent[a] = b;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			// union
			union_parent(a, b);
		}
		else {
			// find
			if (find_parent(a) == find_parent(b)) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}
	return 0;
}