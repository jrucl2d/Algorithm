#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> v;

vector<ll>dpleft;
vector<ll>dpright;

ll gcd(ll a, ll b) {
	while (true) {
		if (b == 0)
			break;
		ll r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	dpleft.push_back(v[0]);
	dpright.push_back(v[n - 1]);
	for (int i = 1; i < n; i++) {
		dpleft.push_back(gcd(dpleft[i - 1], v[i]));
		dpright.push_back(gcd(dpright[i - 1], v[n - i - 1]));
	}

	ll ans = 0;
	int ansIndex = 0;
	for (int index = 0; index < n; index++) {
		ll nowGCD;
		if (index == 0) {
			nowGCD = dpright[n - 2];
		}
		else if (index == n - 1) {
			nowGCD = dpleft[n - 2];
		}
		else {
			nowGCD = gcd(dpleft[index - 1], dpright[n - index - 2]);
		}

		if (v[index] % nowGCD == 0) {
			continue;
		}
		else {
			if (ans < nowGCD) {
				ans = nowGCD;
				ansIndex = index;
			}
		}
	}
	if (ans == 0) {
		cout << -1;
	}
	else {
		cout << ans <<" "<< v[ansIndex];
	}
	return 0;
}