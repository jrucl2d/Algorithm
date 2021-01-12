#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;
ll n, m;
vector<ll> v;
ll ans = 0;

void bisect(ll left, ll right) {

	if (left <= right) {
		ll mid = (left + right) / 2;

		ll res = 0;
		for (ll i = 0; i < n; i++) {
			if (v[i] >= mid) {
				res += (v[i] - mid);
			}
		}
		if (res < m) {
			bisect(left, mid - 1);
		}
		else {
			ans = max(ans, mid);
			bisect(mid + 1, right);
		}
	}
}

int main() {
	cin >> n >> m;
	ll tmpMax = 0;
	for (ll i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		tmpMax = max(tmpMax, tmp);
		v.push_back(tmp);
	}
	bisect(0, tmpMax);
	cout << ans;

	return 0;
}