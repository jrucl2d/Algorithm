#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000

vector<pair<int,int>>v;

int n;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int tmp, tmp2;

	for (int i = 0; i < n; i++) {
		cin >> tmp >> tmp2;
		v.push_back(make_pair(tmp,tmp2));
	}
	sort(v.begin(), v.end()); // first�� ���缭 ����
	vector<int> dp;
	dp.push_back(v[0].second);
	for (int i = 1; i < v.size(); i++) { // LIS ���ϴ� ����
		if (dp.back() < v[i].second)
			dp.push_back(v[i].second);
		else {
			auto it = lower_bound(dp.begin(), dp.end(), v[i].second);
			*it = v[i].second;
		}
	}
	cout << n - dp.size(); // �߶�� �� ���� �ּҰ��� LIS�� �ִ��� ���
}