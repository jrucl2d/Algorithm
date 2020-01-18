#include <iostream>

using namespace std;
#define MAX 8
int arr[MAX];
bool visited[MAX];

int n, m;
void dfs(int count) {
	if (count == m) { // 탈출 조건
		for (int i = 0; i < m; i++) 
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) { // 시작하는 숫자
		if (!visited[i]) { // 방문 안 했던 숫자에 대해서
			visited[i] = true; // 방문 한 것으로 처리
			arr[count] = i + 1; // count가 index 역할을 하므로 해당 index에 i+1 숫자 넣음
			dfs(count + 1); // 다음 인덱스에 대해서 하도록 재귀
			visited[i] = false; // 수열이므로 다시 false로
		 }
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	dfs(0);
}