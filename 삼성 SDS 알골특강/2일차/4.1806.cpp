#include <iostream>
#include <vector>
using namespace std;

int n, m;
int ans = 987654321;
vector<int> v;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	v.push_back(0); // trash value
	// two pointer
	int s = 0, e = 0;
	int sum = v[0];

	while (true) {
		if (sum < m) {
			e += 1;
			sum += v[e];
		}
		else {
			ans = min(ans, e - s + 1);
			sum -= v[s];
			s += 1;
		}
		if (e == n) {
			break;
		}
	}
	if (ans == 987654321) {
		cout << 0;
	}
	else {
		cout << ans;
	}

	return 0;
}