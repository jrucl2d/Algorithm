#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool result(int n) {
	string s = to_string(n);
	bool yes = false;
	if (n < 100) // 두 자리 수 까지는 무조건 해당됨
		return true;
	else if (n >= 100) { // 세 자리 수 이상부터
		for (int i = 0; i < s.size() - 2; i++) {
			if (s[i + 1] - s[i] == s[i + 2] - s[i + 1])
				yes = true;
			else { yes = false; break; }
		}
	}
	return yes;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if(result(i)) count++;
	}
	cout << count;
}