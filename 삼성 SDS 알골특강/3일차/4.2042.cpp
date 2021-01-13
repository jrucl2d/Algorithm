#include <iostream>
using namespace std;
typedef long long ll;

int n, m, k;
int c, p1, p2;
ll nums[2000001];
ll tree[2000001];
int s;

ll makeTree(int node, int left, int right) {
	if (left == right) { // leaf
		if (left <= n) {
			return tree[node] = nums[left];
		}
		else {
			return tree[node] = 0;
		}
	}
	int mid = (left + right) / 2;
	tree[node] = makeTree(node * 2, left, mid);
	tree[node] += makeTree(node * 2 + 1, mid + 1, right);
	return tree[node];
}

ll query(int node, int left, int right, int qleft, int qright) {
	if (qright < left || right < qleft) { // outside
		return 0;
	}
	else if (qleft <= left && right <= qright) { // inside
		return tree[node];
	}
	else { // between
		int mid = (left + right) / 2;
		return query(node * 2, left, mid, qleft, qright)
			+ query(node * 2 + 1, mid + 1, right, qleft, qright);
	}
}

void update(int node, int left, int right, int index, int diff) {
	if (left <= index && index <= right) {
		tree[node] += diff;
		if (left != right) {
			int mid = (left + right) / 2;
			update(node * 2, left, mid, index, diff);
			update(node * 2 + 1, mid + 1, right, index, diff);
		}
	}
}


int main() {

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	// s ±¸ÇÏ±â
	s = 1;
	while (s < n) {
		s *= 2;
	}

	makeTree(1, 1, s);
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, s, b, c - tree[s + b - 1]);
		}
		else {
			cout << query(1, 1, s, b, c) << "\n";
		}
	}

	return 0;
}