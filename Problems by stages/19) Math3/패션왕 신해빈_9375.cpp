#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int t;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	int n;
	string tmp1, tmp2;
	for (int i = 0; i < t; i++) {
		vector<pair<string, int>>clothes;
		int ans = 1;

		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> tmp1 >> tmp2;
			bool isThere = false;
			if (clothes.empty()) // 처음에 그냥 넣기
				clothes.push_back(make_pair(tmp2, 1));
			else { // 이후에
				for (int k = 0; k < clothes.size(); k++) {
					if (tmp2 == clothes[k].first) { // 겹치면 체크
						isThere = true;
						clothes[k].second++; // 해당 개수 증가
					}
				}
				if (!isThere) { // 안 겹치면
					clothes.push_back(make_pair(tmp2, 1));
				}
			}
		}
		for (int j = 0; j < clothes.size(); j++) {
			ans *= (clothes[j].second + 1);
		}
		cout << ans - 1 << '\n';
		clothes.clear();
	}
}