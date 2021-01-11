#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int>v;
int lower_bound(int want) { // ���ϴ� �� �̻��� ó�� ������ ��ġ
	int left = 0;
	int right = n - 1;
	int mid = 0;

	while (right > left) {
		mid = (right + left) / 2;
		if (v[mid] >= want)
			right = mid;
		else left = mid + 1;
	}
	return right;
}
int upper_bound(int want) { // ���ϴ� ������ ū ���� ó�� ������ ��ġ
	int left = 0;
	int right = n - 1;
	int mid = 0;

	while (right > left) {
		mid = (right + left) / 2;
		if (v[mid] > want)
			right = mid;
		else left = mid + 1;
	}
	return right;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	vector<int>ans;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		int up = upper_bound(tmp);
		int low = lower_bound(tmp);
		// ��������. ���� ���� ���Ե� ��� ó���� �� �ǹǷ� + 1�� ����� �Ѵ�. 
		// �������� ���� 10�� �� ���� ������ lower�� 7�� ������,  upper�� 9�� ���´�.
		// ���� upper�� +1�� ����� �Ѵ�.
		if (up == n - 1 && v[up] == tmp)
			up++;
		ans.push_back(up - low);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
}