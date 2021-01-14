#include <iostream>
using namespace std;
typedef long long ll;
ll n, q;
ll nums[270000];
ll tree[270000];
ll s;

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

void update(int node, int left, int right, int index, ll diff) {
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	
	// s ±¸ÇÏ±â
	s = 1;
	while (s < n) {
		s *= 2;
	}

	makeTree(1, 1, s);

	for (int i = 0; i < q; i++) {
		ll a, b, x, y;
		cin >> a >> b >> x >> y;
		if (a <= b) {
			cout << query(1, 1, s, a, b) << "\n";
		}
		else {
			cout << query(1, 1, s, b, a) << "\n";
		}
		update(1, 1, s, x, y - tree[s + x - 1]);
	}

	return 0;
}