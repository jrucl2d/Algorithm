#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int num;
	cin >> num;
	vector<string> ans;
	for (int i = 0; i < num; i++) {
		int h, w, n;
		cin >> h >> w >> n;
		string tmp;
		int ho = n / h + 1;
		int flo = n % h;
		if (n % h == 0) { flo = h; ho -= 1; }// 예외처리
		tmp += to_string(flo);
		if (ho < 10) { tmp += '0'; tmp += to_string(ho); }
		else tmp += to_string(ho);
		ans.push_back(tmp);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}