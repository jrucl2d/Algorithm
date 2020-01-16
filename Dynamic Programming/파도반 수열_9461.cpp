#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long arr[101];

void func(int a) { 
    for (int i = 4; i <= a; i++) {
        arr[i] = arr[i - 2] + arr[i - 3];
		arr[i];
    }
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	arr[1] = 1; arr[2] = 1; arr[3] = 1;

	int t;
	int n;
	vector<int> want;
	int maxN = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		maxN = max(maxN, n);
		want.push_back(n);
	}
	func(maxN);
	for (int i = 0; i < want.size(); i++)
		cout << arr[want[i]] << '\n';
}