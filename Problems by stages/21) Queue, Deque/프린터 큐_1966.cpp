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
			q.push({ tmp,i }); // 큐에 우선순위, 인덱스 순으로 push
			pq.push(tmp); // 우선순위 큐에 우선순위를 넣어 정렬
		}
		int index;
		int priority;
		int count = 0;
		while (!q.empty()) {
			priority = q.front().first; // 현재 큐의 첫 요소의 우선순위 가져옴
			index = q.front().second; // 현재 큐의 첫 요소의 인덱스 가져옴
			q.pop(); // 첫 요소 삭제
			if (pq.top() == priority) { // 현재 우선순위가 최고와 같다면
				count++;
				pq.pop();
				if (index == m) // 거기에 찾던 인덱스가 맞다면 탈출
					break;
			}
			else q.push({ priority,index }); // 큐의 뒤에 다시 넣기
		}
		cout << count << "\n";
	}
}