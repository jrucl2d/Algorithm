#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	vector<int>v;
	vector<int>::iterator it;
	greater<int> gt;
	int n, k; // 종류, 가격
	cin >> n >> k;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), gt); // 내림차순
	int count = 0;
	for (it = v.begin(); it != v.end(); it++) {
		if (k / *it > 0) {
			count += k / *it;
			k = k % *it;
		}
	}
	cout << count;
}