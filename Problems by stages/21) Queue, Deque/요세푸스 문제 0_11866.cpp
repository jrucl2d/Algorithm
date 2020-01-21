#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#include <queue>
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	queue<int>first;
	vector<int>ans;
	for (int i = 1; i <= n; i++)
		first.push(i);
	while (!first.empty()) {
		int tmp;
		// 이전 것 다 뒤로
		for (int i = 0; i < k - 1; i++) {
			tmp = first.front();
			first.pop();
			first.push(tmp);
		}
		// k번째 것 삭제
		tmp = first.front();
		ans.push_back(tmp);
		first.pop();
	}
	cout << "<";
	for (int i = 0; i < ans.size() - 1; i++)
		cout << ans[i] << ", ";
	cout << ans[ans.size() - 1] << '>';
}