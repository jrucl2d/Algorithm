#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include <queue>

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, m;
		cin >> n >> m;
		queue<pair<int,int>>q;
		priority_queue<int> pq;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			q.push({ tmp,i }); // ť�� �켱����, �ε��� ������ push
			pq.push(tmp); // �켱���� ť�� �켱������ �־� ����
		}
		int index;
		int priority;
		int count = 0;
		while (!q.empty()) {
			priority = q.front().first; // ���� ť�� ù ����� �켱���� ������
			index = q.front().second; // ���� ť�� ù ����� �ε��� ������
			q.pop(); // ù ��� ����
			if (pq.top() == priority) { // ���� �켱������ �ְ�� ���ٸ�
				count++;
				pq.pop();
				if (index == m) // �ű⿡ ã�� �ε����� �´ٸ� Ż��
					break;
			}
			else q.push({ priority,index }); // ť�� �ڿ� �ٽ� �ֱ�
		}
		cout << count << "\n";
	}
}