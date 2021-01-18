#include <iostream>
#include <algorithm>
using namespace std;
// ũ�罺Į �˰��� -> ����, union/find
// ������ �������� ���� -> union/find�� ��ġ�� ��
int parent[1001];
class Info {
public:
	int a;
	int b;
	int c;
	Info() {
		this->a = 0;
		this->b = 0;
		this->c = 0;
	};
};

int find_p(int a) {
	if (parent[a] != a) {
		parent[a] = find_p(parent[a]);
	}
	return parent[a];
}

void union_p(int a, int b) {
	a = find_p(a);
	b = find_p(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}
int n, m;
Info edge[100001];

bool myComp(Info x, Info y) {
	return x.c < y.c;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i].a = a;
		edge[i].b = b;
		edge[i].c = c;
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	sort(edge, edge + m, myComp); // ������� ����
	int ans = 0;
	// int cnt = 0; // -> ��ü ��尡 ����Ǵ��� �ľ��ϱ� ���� ����
	for (int i = 0; i < m; i++) {
		// ���� ���� �о��
		int a, b, c;
		a = edge[i].a;
		b = edge[i].b;
		c = edge[i].c;
		// ���� �����?
		if (find_p(a) != find_p(b)) {
			// �ٸ� �׷��̸� ����
			union_p(a, b);
			ans += c;
			// cnt+=1; // -> ���� Ƚ���� üũ�ؼ� ���� ���� n-1�� ���ƾ� ��� ��尡 ���� �� ��.
		}
	}
	cout << ans;
	return 0;
}