#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define INF 1000000000
typedef long long ll;
ll x, y;

int main() {

	cin >> x >> y;

	ll want = (y * 100) / x;
	// 99%에서 100%가 되지는 못한다.
	if (want == 99 || want == 100) {
		cout << -1;
		return 0;
	}

	int left = 0;
	int right = INF + 1;
	int mid = 0;
	while (left < right) {
		mid = (left + right) / 2;
		ll tmp = (100 * (y + mid)) / (x + mid);
		if (tmp <= want) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	if (right > INF) {
		cout << -1;
	}
	else {
		cout << right;
	}
	return 0;
}