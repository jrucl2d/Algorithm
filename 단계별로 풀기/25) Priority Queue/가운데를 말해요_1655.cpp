#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100000 + 1 + 1

// 1. �ִ� ���� ũ��� �ּ� ���� ũ�⺸�� �ϳ� ũ�ų� ����.
// 2. �ִ� ���� top�� �ּ� ���� ���� ���� ���Һ��� �۰ų� ����.
// 3. �� ���ǿ� ���� ������ �ִ� ���� �ּ� ���� top�� swap ���ش�.
// �̷��� �ϸ� �ִ� ���� top�� �߰� ���� �ȴ�.

int n;
priority_queue<int, vector<int>, less<int>> max_heap; // ū ����� ����
priority_queue<int, vector<int>, greater<int>> min_heap; // ���� ����� ����
int arr[MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	vector<int>ans;
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;

		// 1�� ����
		if (max_heap.empty()) // �ִ� ���� �ּ� ������ Ŀ�� �ϹǷ� ó���� �ִ� ���� �ִ´�.
			max_heap.push(tmp);
		else if (max_heap.size() == min_heap.size()) // ���Ƶ� �ִ� ���� �ִ´�.
			max_heap.push(tmp);
		else // �̿��� ��쿡�� �ּ� ���� �ִ´�.
			min_heap.push(tmp);

		// 2�� ����
		if (!max_heap.empty() && !min_heap.empty()) { // �� ���� ���� ������� �ʰ�
			if (max_heap.top() > min_heap.top()) { // �ִ� ���� top�� �ּ� ������ ũ��
				
				// �� ���� top�� ��ü
				int a = max_heap.top();
				int b = min_heap.top();

				max_heap.pop();
				min_heap.pop();

				max_heap.push(b);
				min_heap.push(a);
			}
		}
		ans.push_back(max_heap.top()); // �ִ� ���� top�� �߰���.
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
	
}