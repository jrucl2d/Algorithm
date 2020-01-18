#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, string>>v;
	int a;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> a >> s;
		v.push_back(make_pair(a, s)); // 거꾸로 집어 넣어서
	}
	vector<pair<int, string>>v2;
	for (int i = 1; i <= 200; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i == v[j].first) { // 해당 나이와 같은 경우 원래 벡터 순서대로 넣어줌
				v2.push_back(make_pair(i, v[j].second));
				v[j].first = 0; // 이미 해결한 것은 나이를 0으로 만들어 검색 불가하도록 만든다
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << v2[i].first << ' ' << v2[i].second << '\n';
}