#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 이분 탐색
// 1. 이미 정렬이 되어 있어야 한다.
// 2. left, right로 mid 값을 정해준다.
// 3. mid와 원하는 값 비교

int n;
vector<int>v;
int find(int want) {
	int left = 0;
	int right = n - 1;
	int mid = 0;
	int ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (v[mid] < want) { // 원하는 것이 mid보다 오른쪽인 경우
			left = mid + 1;
		}
		else if (v[mid] > want) { // 원하는 것이 mid보다 왼쪽인 경우
			right = mid - 1;
		}
		else { ans = 25; break; } // 대충 아무 숫자
	}
	if (ans == 25)
		return 1;
	else return 0;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end()); // 정렬이 되어있어야 한다.

	int m;
	cin >> m;
	int tmp;
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		ans.push_back(find(tmp));
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}