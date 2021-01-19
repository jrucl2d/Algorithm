#include <iostream>

using namespace std;
typedef long long ll;

int n, m, p[100010];
ll d[100010]; // d : root에서 자신까지의 거리

int find_p(int a) {
	if (p[a] == a) return a;
	int the_root = find_p(p[a]); // root를 찾음
	// a 자신의 부모를 root로 갱신하기 전에
	// 자신의 거리를 기존 자기 거리 + 부모부터 root까지의 거리로 갱신 -> 자신의 root까지의 거리로
	d[a] += d[p[a]];
	p[a] = the_root;
	return the_root;
}

void union_p(int a, int b, int w) {
	int root_of_a = find_p(a);
	int root_of_b = find_p(b);
	if (root_of_a == root_of_b) return;
	ll x = d[a], y = d[b]; // x, y는 a, b의 각자 루트에서부터의 거리
	// a = root_of_a + x
	// b = root_of_b + y -> root_of_b = b - y
	// b = a + w = root_of_a + x
	// root_of_b = root_of_a + x + w - y -> root_of_a가 새로운 root가 되므로 거리 0
	d[root_of_b] = x + w - y;
	// 큰 b의 루트가 작은 a의 루트를 부모로 가짐
	p[root_of_b] = root_of_a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			p[i] = i;
			d[i] = 0; // p가 자기 자신이고 그 거리는 0
		}
		char cmd;
		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> cmd >> a >> b;
			if (cmd == '?') {
				if (find_p(a) != find_p(b)) {
					cout << "UNKNOWN" << "\n";
				}
				else {
					cout << d[b] - d[a] << "\n";
				}
			}
			else if (cmd == '!') {
				int w;
				cin >> w;
				union_p(a, b, w);
			}
		}
	}
	return 0;
}