#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int num;
	cin >> num;
	vector<int> ans;
	int arr[15][15] = { 0, };
	for (int i = 1; i < 15; i++)
		arr[0][i] = i;
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}

	for (int i = 0; i < num; i++) {
		int k, n;
		cin >> k >> n;
		ans.push_back(arr[k][n]);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}