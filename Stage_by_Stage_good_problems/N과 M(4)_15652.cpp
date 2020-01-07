#include <iostream>

using namespace std;
#define MAX 8
int arr[MAX];
//bool visited[MAX];

int n, m;
void dfs(int start, int count) { // start 매개변수 추가
	if (count == m) { // 탈출 조건
		for (int i = 0; i < m; i++) 
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = start; i < n; i++) { // 시작하는 숫자
		//if (!visited[i]) {				// <- 이 조건을 없애서 같은 수도 출력할 수 있도록
			//visited[i] = true;			// <- 이 조건도 불필요
			arr[count] = i + 1; // count가 index 역할을 하므로 해당 index에 i+1 숫자 넣음
			dfs(i, count + 1); // 다음 인덱스에 대해서 하도록 재귀
			//visited[i] = false;			// <- 이 조건도 불필요
		//}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	dfs(0, 0);
}