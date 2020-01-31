#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// �̺� Ž��
// 1. �̹� ������ �Ǿ� �־�� �Ѵ�.
// 2. left, right�� mid ���� �����ش�.
// 3. mid�� ���ϴ� �� ��

int n;
vector<int>v;
int find(int want) {
	int left = 0;
	int right = n - 1;
	int mid = 0;
	int ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (v[mid] < want) { // ���ϴ� ���� mid���� �������� ���
			left = mid + 1;
		}
		else if (v[mid] > want) { // ���ϴ� ���� mid���� ������ ���
			right = mid - 1;
		}
		else { ans = 25; break; } // ���� �ƹ� ����
	}
	if (ans == 25)
		return 1;
	else return 0;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end()); // ������ �Ǿ��־�� �Ѵ�.

	int m;
	cin >> m;
	int tmp;
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		ans.push_back(find(tmp));
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}