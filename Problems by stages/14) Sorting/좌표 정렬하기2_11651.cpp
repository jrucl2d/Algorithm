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
	vector<pair<int, int>>v;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end()); // x에 대해서 먼저 정렬
	vector<pair<int, int>>v2;
	for (int i = 0; i < n; i++) { 
		v2.push_back(make_pair(v[i].second, v[i].first));
	}
	sort(v2.begin(), v2.end()); // y로 정렬
	vector<pair<int, int>>v3;;
	for (int i = 0; i < n; i++) { // 다시 벡터에 넣고
		v3.push_back(make_pair(v2[i].second, v2[i].first));
	}
	for (int i = 0; i < n; i++)
		cout << v3[i].first << ' ' << v3[i].second << '\n';
}