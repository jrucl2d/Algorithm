#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n;
vector<ll> v;

class Runner {
	ll value;
	int position;
}

void merge() {

}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	return 0;
}