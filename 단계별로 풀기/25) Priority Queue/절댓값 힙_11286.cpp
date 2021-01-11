#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
typedef long long ll;

ll heap[MAX];
int n;
int top = 0;

// ���밪 ��ȯ �Լ�
ll ABS(ll data) {
	return data > 0 ? data : -data;
}

void push(ll data) {
	// ���� ���� ���� ������ �߰�
	heap[++top] = data;

	// child�� parent�� ���ؼ� ���� �����ϴ� ����
	int c = top; // ���� ����ϸ� �� ����
	int p = c / 2;

	// ����ϴ� �������� Ž���ؼ� �� ����
	while (c > 1) {
		if (ABS(heap[p]) == ABS(heap[c])) { // ���� ���밪�� ���ٸ�
			if (heap[p] >= heap[c]) { // �׷��� �θ� �� ũ��
				// �θ�� �ڽ� �� ��ȯ
				ll tmp = heap[p];
				heap[p] = heap[c];
				heap[c] = tmp;
			}
		}
		else if(ABS(heap[p]) > ABS(heap[c])) { // �׳� �θ� �� ũ��
			// �θ�� �ڽ� �� ��ȯ
			ll tmp = heap[p];
			heap[p] = heap[c];
			heap[c] = tmp;
		}
		c = p; // �θ� ���� �ö�(��� Ž��)
		p = c / 2; // ���� �ڽ��� �θ�� �ö����Ƿ� �� �ڽ��� �θ�� ���� ����
	}
}

int pop() {
	// ���� ���� ù ��° ����(�ּҰ�)�� ��ȯ
	ll ans = heap[1];

	// ù ���ҿ� �� ���� ��ü, ������ �� �ּҰ� ������.
	ll tmp = heap[1];
	heap[1] = heap[top];
	heap[top] = tmp;
	top--;

	// �ٽ� ���� ����
	int p = 1;
	int c = p * 2; // �ڽ��� ���� �ڽ�
	if (c <= top - 1) { // �ڽ� ��� ��, �� �߿��� ���밪�� ���� ���� c�� ����
		if (ABS(heap[c]) == ABS(heap[c + 1])) // �ٵ� ������ �׳� �� ���� ������ ����
			c = heap[c] < heap[c + 1] ? c : c + 1;
		else c = ABS(heap[c]) < ABS(heap[c + 1]) ? c : c + 1;
	}

	// �ϰ��ϴ� �������� Ž���ؼ� �� ����
	while (c <= top) {
		if (ABS(heap[c]) < ABS(heap[p])) { // �׳� �θ� �� ū ���
			ll tmp = heap[p];
			heap[p] = heap[c];
			heap[c] = tmp;
		}
		else if (ABS(heap[c]) == ABS(heap[p])) { // ���밪�� ���ٸ�
			if (heap[p] >= heap[c]) { // �ٵ� �θ� �� ũ��
				// �θ�� �ڽ� �� ��ȯ
				ll tmp = heap[p];
				heap[p] = heap[c];
				heap[c] = tmp;
			}
		}
		p = c; // �θ� ��尡 �ڽ� ������ ������
		c = c * 2; // �ڽ��� ���� ���� �� ��� �ؼ� ���ο� �ڽ����� ã�ư�

		if (c <= top - 1) { // �ڽ� ��� ��, �� �߿��� ���밪�� ���� ���� c�� ����
			if (ABS(heap[c]) == ABS(heap[c + 1])) // �ٵ� ������ �׳� �� ���� ������ ����
				c = heap[c] < heap[c + 1] ? c : c + 1;
			else c = ABS(heap[c]) < ABS(heap[c + 1]) ? c : c + 1;
		}
	}

	return ans; // ó���� �����ߴ� �ִ밪 ����
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