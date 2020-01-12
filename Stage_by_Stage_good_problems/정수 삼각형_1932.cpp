#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 501 + 1

int arr[MAX][MAX];
int ans[MAX][MAX];

int n;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)  // 정보 입력받기
		for (int j = 1; j <= i; j++) 
			cin >> arr[i][j];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			ans[i][j] = arr[i][j] + max(ans[i - 1][j], ans[i - 1][j - 1]);
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum = max(sum, ans[n][i]);
	cout << sum;
}