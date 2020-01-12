#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 501 + 1 // 인덱스 범위 벗어나는 것 방지

int arr[MAX][MAX];
int ans[MAX][MAX];

int n;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)  // 입력 받기
		for (int j = 1; j <= i; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++) { // 해당 자리의 값은 이전 자리에서 올 수 있었던 결과에 현재 자리를 더한 값
		for (int j = 1; j <= i; j++) {
			ans[i][j] = arr[i][j] + max(ans[i - 1][j], ans[i - 1][j - 1]);
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum = max(sum, ans[n][i]);
	cout << sum;
}
