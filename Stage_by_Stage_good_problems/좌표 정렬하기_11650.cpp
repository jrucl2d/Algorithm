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
		v.push_back(make_pair(b, a)); // 거꾸로 집어 넣어서
	}
	sort(v.begin(), v.end()); // second에 대해서 먼저 정렬
	vector<pair<int, int>>v2;
	for (int i = 0; i < n; i++) { // first로 다시 벡터에 넣고
		v2.push_back(make_pair(v[i].second, v[i].first));
	}
	sort(v2.begin(), v2.end()); // first로 정렬
	for (int i = 0; i < n; i++)
		cout << v2[i].first << ' ' << v2[i].second << '\n';
}