#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int>v;
	int a;
	for (int i = 0; i < 8; i++) {
		cin >> a;
		v.push_back(a);
	}
	int asc = 0;
	int des = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == i + 1) {
			asc++;
		}
		else if (v[i] == 8 - i) {
			des++;
		}
	}
	if (asc == 8) cout << "ascending";
	else if (des == 8) cout << "descending";
	else if (asc != 8 && des != 8) cout << "mixed";
}