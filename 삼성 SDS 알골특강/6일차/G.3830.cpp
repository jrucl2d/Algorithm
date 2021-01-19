#include <iostream>

using namespace std;
typedef long long ll;

int n, m, p[100010];
ll d[100010]; // d : root���� �ڽű����� �Ÿ�

int find_p(int a) {
	if (p[a] == a) return a;
	int the_root = find_p(p[a]); // root�� ã��
	// a �ڽ��� �θ� root�� �����ϱ� ����
	// �ڽ��� �Ÿ��� ���� �ڱ� �Ÿ� + �θ���� root������ �Ÿ��� ���� -> �ڽ��� root������ �Ÿ���
	d[a] += d[p[a]];
	p[a] = the_root;
	return the_root;
}

void union_p(int a, int b, int w) {
	int root_of_a = find_p(a);
	int root_of_b = find_p(b);
	if (root_of_a == root_of_b) return;
	ll x = d[a], y = d[b]; // x, y�� a, b�� ���� ��Ʈ���������� �Ÿ�
	// a = root_of_a + x
	// b = root_of_b + y -> root_of_b = b - y
	// b = a + w = root_of_a + x
	// root_of_b = root_of_a + x + w - y -> root_of_a�� ���ο� root�� �ǹǷ� �Ÿ� 0
	d[root_of_b] = x + w - y;
	// ū b�� ��Ʈ�� ���� a�� ��Ʈ�� �θ�� ����
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
			d[i] = 0; // p�� �ڱ� �ڽ��̰� �� �Ÿ��� 0
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