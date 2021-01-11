#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int lowerbound(int tar, int size) {
	int mid, left = 0, right = size - 1;
	while (right > left) {
		mid = (left + right) / 2;
		if (tar <= v[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return right;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	int tmp;
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (v.empty()) { // 처음에 비었을 때
			v.push_back(tmp);
			count++;
		}
		else {
			if (v.back() < tmp) {
				v.push_back(tmp);
				count++;
			}
			else {
				v[lowerbound(tmp, v.size())] = tmp;;
			}
		}
	}
	cout << count;
}