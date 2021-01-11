#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int>v;
int lower_bound(int want) { // 원하는 값 이상이 처음 나오는 위치
	int left = 0;
	int right = n - 1;
	int mid = 0;

	while (right > left) {
		mid = (right + left) / 2;
		if (v[mid] >= want)
			right = mid;
		else left = mid + 1;
	}
	return right;
}
int upper_bound(int want) { // 원하는 값보다 큰 것이 처음 나오는 위치
	int left = 0;
	int right = n - 1;
	int mid = 0;

	while (right > left) {
		mid = (right + left) / 2;
		if (v[mid] > want)
			right = mid;
		else left = mid + 1;
	}
	return right;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	vector<int>ans;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		int up = upper_bound(tmp);
		int low = lower_bound(tmp);
		// 예외조건. 끝의 수가 포함될 경우 처리가 안 되므로 + 1을 해줘야 한다. 
		// 예제에서 끝에 10이 세 개가 있으면 lower은 7이 나오고,  upper은 9가 나온다.
		// 따라서 upper에 +1을 해줘야 한다.
		if (up == n - 1 && v[up] == tmp)
			up++;
		ans.push_back(up - low);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
}