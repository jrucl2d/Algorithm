#include <iostream>
using namespace std;

typedef long long ll;

ll heap[100001];
int n;
int top = 0;

void push(ll data) {
	heap[++top] = data;

	int c = top;
	int p = c / 2;

	while (c > 1 && heap[c] < heap[p]) {
		ll tmp = heap[p];
		heap[p] = heap[c];
		heap[c] = tmp;

		c = p;
		p = c / 2;
	}
}

int pop() {
	ll ans = heap[1];

	ll tmp = heap[1];
	heap[1] = heap[top];
	heap[top] = tmp;
	top--; 

	int p = 1;
	int c = p * 2;
	if (c <= top - 1)
		c = heap[c] < heap[c + 1] ? c : c + 1;

	while (c <= top && heap[c] < heap[p]) {
		ll tmp = heap[p];
		heap[p] = heap[c];
		heap[c] = tmp;

		p = c;
		c = c * 2;
		if (c <= top - 1)
			c = heap[c] < heap[c + 1] ? c : c + 1;
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	ll tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 0) {
			if (top == 0)
				cout << 0 << '\n';
			else
				cout << pop() << '\n';
		}
		else
			push(tmp);
	}
}