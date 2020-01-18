#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	vector<int>v;
	vector<int>::iterator it;
	greater<int> gt;
	int n, k; // Á¾·ù, °¡°Ý
	cin >> n >> k;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), gt); // ³»¸²Â÷¼ø
	int count = 0;
	for (it = v.begin(); it != v.end(); it++) {
		if (k / *it > 0) {
			count += k / *it;
			k = k % *it;
		}
	}
	cout << count;
}
