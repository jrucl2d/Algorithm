#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	vector<int> arr;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	// two pointer
	int count = 0;
	int sum = arr[0];
	int s = 0, e = 0;

	while (true) {

		if (sum == m) {
			count += 1;
			sum -= arr[s];
			s += 1;
			e += 1;
			if (e >= n) {
				break;
			}
			sum += arr[e];

			continue;
		}
		else if (sum < m) {
			e += 1;
			if (e >= n) {
				break;
			}
			sum += arr[e];
			continue;
		}
		else {
			sum -= arr[s];
			s += 1;
			continue;
		}
	}
	cout << count;
	return 0;
}