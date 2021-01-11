#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int fac(int n) {
	if (n == 1 || n == 0)
		return 1;
	return n * fac(n - 1);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	cout << fac(n) / (fac(k) * fac(n - k)); // n!/k!(n-k)!
}