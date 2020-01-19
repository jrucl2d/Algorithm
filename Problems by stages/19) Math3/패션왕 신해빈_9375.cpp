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
			if (clothes.empty()) // ó���� �׳� �ֱ�
				clothes.push_back(make_pair(tmp2, 1));
			else { // ���Ŀ�
				for (int k = 0; k < clothes.size(); k++) {
					if (tmp2 == clothes[k].first) { // ��ġ�� üũ
						isThere = true;
						clothes[k].second++; // �ش� ���� ����
					}
				}
				if (!isThere) { // �� ��ġ��
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