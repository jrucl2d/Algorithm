#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100000 + 1

int arr[MAX];
int visited[MAX]; // 지나온 시간 기록

int n, k;

void bfs(int a) {
	queue<int>q;
	q.push(a); // 첫 지점 큐에 추가

	while (!q.empty()) {

		a = q.front();
		q.pop(); // 맨 앞의 요소 삭제
		if (a == k) // 탈출 조건
			break;

		if (0 <= a - 1 && visited[a - 1] == 0) { // 범위 내에서 a-1의 위치가 방문 전이라면
			visited[a - 1] = visited[a] + 1;
			q.push(a - 1);
		}
		if (a + 1 < MAX && visited[a + 1] == 0) { // 범위 내에서 a+1의 위치가 방문 전이라면
			visited[a + 1] = visited[a] + 1;
			q.push(a + 1);
		}
		if (2 * a < MAX && visited[a * 2] == 0) {
			visited[a * 2] = visited[a] + 1;
			q.push(2 * a);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n >> k;
	visited[n] = 0; // 처음에는 0초에서 시작
	bfs(n);
	cout << visited[k];
}