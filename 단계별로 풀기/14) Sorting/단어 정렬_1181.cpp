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
	sort(v.begin(), v.end()); // ���ĺ� ������ ����
	vector<string>v2;
	for (int i = 1; i <= 50; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j].size() == i) { // Ư�� ���̿� �ش�Ǹ�
				v2.push_back(v[j]); // ���ο� ���Ϳ� �ְ�
				v[j] = ""; // �� ���� �����
			}
		}
	} 
	cout << v2[0] << '\n'; 
	for (int i = 1; i < v2.size(); i++) {
		string s = v2[i];
		if (s == v2[i - 1]) // �ߺ� �ƴ� �͸� ���
			continue;
		cout << v2[i] << '\n';
	}
}