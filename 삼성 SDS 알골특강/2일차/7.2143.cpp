#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ll t;
	int n, m;
	vector<ll> v1tmp;
	vector<ll> v2tmp;
	vector<ll> v1;
	vector<ll> v2;
	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		v1tmp.push_back(tmp);
	}
	for (int sumCnt = 1; sumCnt <= n; sumCnt++) {
		for (int start = 0; start < n; start++) {
			ll tmp = 0;
			if (start + sumCnt > n) {
				continue;
			}
			for (int j = start; j < start + sumCnt; j++) {
				tmp += v1tmp[j];
			}
			v1.push_back(tmp);
		}
	}
	sort(v1.begin(), v1.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		ll tmp;
		cin >> tmp;
		v2tmp.push_back(tmp);
	}
	for (int sumCnt = 1; sumCnt <= m; sumCnt++) {
		for (int start = 0; start < m; start++) {
			ll tmp = 0;
			if (start + sumCnt > m) {
				continue;
			}
			for (int j = start; j < start + sumCnt; j++) {
				tmp += v2tmp[j];
			}
			v2.push_back(tmp);
		}
	}
	sort(v2.begin(), v2.end());

	// two pointer
	int s = 0, e = v2.size() - 1;
	ll ans = 0;
	ll sum = v1[s] + v2[e];
	while (true) {
		sum = v1[s] + v2[e];
		if (sum < t) {
			s += 1;
		}
		else if (sum > t) {
			e -= 1;
		}
		else {
			ll cnt1 = 1;
			while (s + 1 < v1.size() && v1[s] == v1[s + 1]) {
				cnt1 += 1;
				s += 1;
			}
			s += 1;
			ll cnt2 = 1;
			while (e - 1 >= 0 && v2[e] == v2[e - 1]) {
				cnt2 += 1;
				e -= 1;
			}
			e -= 1;
			ans += cnt1 * cnt2;
		}
		if (s == v1.size() || e == -1) {
			break;
		}
	}
	cout << ans;

	return 0;
}