#include <iostream>
#include <algorithm>
using namespace std;
// 크루스칼 알고리즘 -> 정렬, union/find
// 간선을 비용순으로 정렬 -> union/find로 합치면 됨
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
	sort(edge, edge + m, myComp); // 비용으로 정렬
	int ans = 0;
	// int cnt = 0; // -> 전체 노드가 연결되는지 파악하기 위한 변수
	for (int i = 0; i < m; i++) {
		// 간선 정보 읽어옴
		int a, b, c;
		a = edge[i].a;
		b = edge[i].b;
		c = edge[i].c;
		// 둘이 연결됨?
		if (find_p(a) != find_p(b)) {
			// 다른 그룹이면 연결
			union_p(a, b);
			ans += c;
			// cnt+=1; // -> 연결 횟수를 체크해서 간선 개수 n-1과 같아야 모든 노드가 연결 된 것.
		}
	}
	cout << ans;
	return 0;
}