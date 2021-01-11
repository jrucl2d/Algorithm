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
	vector<string>v;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end()); // 알파벳 순으로 정렬
	vector<string>v2;
	for (int i = 1; i <= 50; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j].size() == i) { // 특정 길이에 해당되면
				v2.push_back(v[j]); // 새로운 벡터에 넣고
				v[j] = ""; // 그 값은 비워줌
			}
		}
	} 
	cout << v2[0] << '\n'; 
	for (int i = 1; i < v2.size(); i++) {
		string s = v2[i];
		if (s == v2[i - 1]) // 중복 아닌 것만 출력
			continue;
		cout << v2[i] << '\n';
	}
}