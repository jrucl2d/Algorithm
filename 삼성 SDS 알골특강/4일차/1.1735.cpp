#include<iostream>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	ll ac, ap, bc, bp;
	cin >> ac >> ap;
	cin >> bc >> bp;
	ll parentGi = gcd(ap, bp);
	ll addedp = (ap / parentGi) * bp;
	ll addedc = ac * (bp /parentGi) + bc * (ap / parentGi);
	ll addedGi = gcd(addedp, addedc);
	cout << addedc / addedGi <<" " << addedp / addedGi;
	return 0;
}