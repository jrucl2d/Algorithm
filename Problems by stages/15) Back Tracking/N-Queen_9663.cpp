#include <iostream>
using namespace std;
#define MAX 15
int n;
int ans = 0;
int col[MAX]; // 값이 low 

bool can(int n) {
	for (int i = 0; i < n; i++) { // i == n 이 될 수 없으므로 열이 같을 수는 없다.
		// 같은 행에 있거나 대각선에 있으면 false
		if (col[i] == col[n] || (n - i) == abs(col[n] - col[i]))
			return false;
	}
	return true;
}
void dfs(int count) {
	if (count == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		col[count] = i; // 행과 열을 짝지어줌
		if (can(count))
			dfs(count + +1);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	dfs(0);
	cout << ans << '\n';
}