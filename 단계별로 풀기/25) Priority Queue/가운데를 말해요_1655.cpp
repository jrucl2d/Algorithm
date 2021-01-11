#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100000 + 1 + 1

// 1. 최대 힙의 크기는 최소 힙의 크기보다 하나 크거나 같다.
// 2. 최대 힙의 top은 최소 힙의 가장 작은 원소보다 작거나 같다.
// 3. 이 조건에 맞지 않으면 최대 힙과 최소 힙의 top을 swap 해준다.
// 이렇게 하면 최대 힙의 top이 중간 값이 된다.

int n;
priority_queue<int, vector<int>, less<int>> max_heap; // 큰 놈부터 나옴
priority_queue<int, vector<int>, greater<int>> min_heap; // 작은 놈부터 나옴
int arr[MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	vector<int>ans;
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;

		// 1번 조건
		if (max_heap.empty()) // 최대 힙이 최소 힙보다 커야 하므로 처음에 최대 힙에 넣는다.
			max_heap.push(tmp);
		else if (max_heap.size() == min_heap.size()) // 같아도 최대 힙에 넣는다.
			max_heap.push(tmp);
		else // 이외의 경우에만 최소 힙에 넣는다.
			min_heap.push(tmp);

		// 2번 조건
		if (!max_heap.empty() && !min_heap.empty()) { // 두 개의 힙이 비어있지 않고
			if (max_heap.top() > min_heap.top()) { // 최대 힙의 top이 최소 힙보다 크면
				
				// 두 힙의 top을 교체
				int a = max_heap.top();
				int b = min_heap.top();

				max_heap.pop();
				min_heap.pop();

				max_heap.push(b);
				min_heap.push(a);
			}
		}
		ans.push_back(max_heap.top()); // 최대 힙의 top이 중간값.
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
	
}