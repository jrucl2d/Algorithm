#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, c;
vector<int>place;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> c;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp; place.push_back(tmp);
	}
	sort(place.begin(), place.end());

	int left = 1; // ������ �ּ� �Ÿ� 1
	int right = place[n - 1] - place[0]; // ������ �ִ� �Ÿ�
	int mid = 0;
	int ans = 0; 
	int count = 1; // ù ��°�� �����⸦ �̹� ��ġ�ϰ� �����Ѵ�.
	while (left <= right) { // ��ȣ�� ���� ������ �ִܰŸ� �� �ִ븦 ã�� ���ؼ�.
		mid = (left + right) / 2;
		count = 1; 
		int start = place[0]; // ù ��°�� ������

		// ���� mid ���� �ּ� �����̹Ƿ� ù ��°���� �����ؼ� �ּ� ���� ������ ���� ������ ��ġ
		// ���� ��ġ�ϸ� ���� ��Ҹ� �װ����� �ٽ� �����ؼ� �� �ּ� ���� ������ ���� ��ġ
		for (int i = 1; i < n; i++) {
			if (place[i] - start >= mid) {
				start = place[i];
				count++;
			}
		}
		if (count >= c) { // ��ġ ���� Ƚ������ �� ���� ��ġ�ߴ�.
			ans = mid; // ������ mid ���� �ִܰŸ� �� �ִ�� ����.
			left = mid + 1; // �� �ִ밡 �����ϴ��� �˻�
		}
		else right = mid - 1; // ��ġ ���� Ƚ������ �� ������ �� ���� ���ݿ��� ã��
	}
	cout << ans;
}