#include <iostream>
using namespace std;
#define MAX 15
int n;
int ans = 0;
int col[MAX]; // ���� low 

bool can(int n) {
	for (int i = 0; i < n; i++) { // i == n �� �� �� �����Ƿ� ���� ���� ���� ����.
		// ���� �࿡ �ְų� �밢���� ������ false
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
		col[count] = i; // ��� ���� ¦������
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