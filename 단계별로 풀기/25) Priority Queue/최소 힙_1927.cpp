#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
typedef long long ll;

ll heap[MAX];
int n;
int top = 0;

void push(ll data) {
	// ���� �� ���� ������ ���� ����
	heap[++top] = data;

	int c = top;
    int p = c / 2;

	// �ϰ��ϴ� �������� Ž���ϸ� ���� ����
	while (c > 1 && heap[c] < heap[p]) {
		ll tmp = heap[p];
		heap[p] = heap[c];
		heap[c] = tmp;

		c = p;
        p = c / 2;
	}
}

int pop() {
	// ���� ���� ù ��° ����(�ּҰ�)�� ��ȯ
	ll ans = heap[1];

	// ù ���ҿ� �� ���� ��ü, ������ �� �ּҰ� ������.
	ll tmp = heap[1];
	heap[1] = heap[top];
	heap[top] = tmp;
	top--; // ���� ���� ����
	
	int p = 1;
	int c = p * 2;
	if (c <= top - 1) // �� �� �� ���� �ڽ����� c�� ����
		c = heap[c] < heap[c + 1] ? c : c + 1;

	// �ϰ��ϴ� �������� Ž���ϸ� ���� ����
	while (c <= top && heap[c] < heap[p]) {
		ll tmp = heap[p];
		heap[p] = heap[c];
		heap[c] = tmp;

		p = c;
		c = c * 2;
		if (c <= top - 1) // �� �� �� ���� �ڽ����� c�� ����
			c = heap[c] < heap[c + 1] ? c : c + 1;
	}
	return ans; // �ּҰ� ��ȯ
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	ll tmp;
	vector<ll>ans;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 0) {
			if (top == 0) // ���� ���� ����ִٸ� 0 ���
				ans.push_back(0);
			else
				ans.push_back(pop());
		}
		else
			push(tmp); // ���� ���� ���� ����
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}