#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
typedef long long ll;

int heap[MAX];
int n;
int top = 0;

void push(ll data) {
	// 힙의 제일 끝에 데이터 추가
	heap[++top] = data;

	// child와 parent를 비교해서 최대 힙을 구성하는 과정
	int c = top; // 위로 상승하며 힙 구현
	int p = c / 2;

	// 상승하는 방향으로 탐색해서 힙 구성
	while (c > 1 && heap[p] < heap[c]) {
		
		// 부모와 자식 값 교환
		ll tmp = heap[p];
		heap[p] = heap[c];
		heap[c] = tmp;

		c = p; // 부모 노드로 올라감(계속 탐색)
		p = c / 2; // 원래 자식이 부모로 올라갔으므로 그 자식의 부모로 새로 설정
	}
}

int pop() {
	// 힙의 가장 첫 번째 원소(최대값)을 반환
	ll ans = heap[1];

	// 첫 원소와 끝 원소 교체, 끝으로 간 최대값 버린다.
	ll tmp = heap[1];
	heap[1] = heap[top];
	heap[top] = tmp;
	top--;
	
	// 다시 힙을 구성
	int p = 1;
	int c = p * 2; // 자식은 왼쪽 자식
	if (c <= top - 1) // 자식 노드 좌, 우 중에서 더 큰 것을 c에 저장
		c = heap[c] > heap[c + 1] ? c : c + 1;
	
	// 하강하는 방향으로 탐색해서 힙 구성
	while (c <= top && heap[c] > heap[p]) {
		ll tmp = heap[p];
		heap[p] = heap[c];
		heap[c] = tmp;

		p = c; // 부모 노드가 자식 쪽으로 내려감
		c = c * 2; // 자식은 원래 값의 두 배로 해서 새로운 자식으로 찾아감

		if (c <= top - 1) // 자식 노드 좌, 우 중에서 더 큰 것을 c에 저장
			c = heap[c] > heap[c + 1] ? c : c + 1;
	}

	return ans; // 처음에 저장했던 최대값 리턴
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