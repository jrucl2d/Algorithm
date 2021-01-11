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
	// 힙의 맨 끝에 데이터 집어 넣음
	heap[++top] = data;

	int c = top;
    int p = c / 2;

	// 하강하는 방향으로 탐색하며 힙을 구성
	while (c > 1 && heap[c] < heap[p]) {
		ll tmp = heap[p];
		heap[p] = heap[c];
		heap[c] = tmp;

		c = p;
        p = c / 2;
	}
}

int pop() {
	// 힙의 가장 첫 번째 원소(최소값)을 반환
	ll ans = heap[1];

	// 첫 원소와 끝 원소 교체, 끝으로 간 최소값 버린다.
	ll tmp = heap[1];
	heap[1] = heap[top];
	heap[top] = tmp;
	top--; // 힙의 끝을 줄임
	
	int p = 1;
	int c = p * 2;
	if (c <= top - 1) // 좌 우 중 작은 자식으로 c를 설정
		c = heap[c] < heap[c + 1] ? c : c + 1;

	// 하강하는 방향으로 탐색하며 힙을 구성
	while (c <= top && heap[c] < heap[p]) {
		ll tmp = heap[p];
		heap[p] = heap[c];
		heap[c] = tmp;

		p = c;
		c = c * 2;
		if (c <= top - 1) // 좌 우 중 작은 자식으로 c를 설정
			c = heap[c] < heap[c + 1] ? c : c + 1;
	}
	return ans; // 최소값 반환
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
			if (top == 0) // 만약 힙이 비어있다면 0 출력
				ans.push_back(0);
			else
				ans.push_back(pop());
		}
		else
			push(tmp); // 값을 힙에 집어 넣음
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}