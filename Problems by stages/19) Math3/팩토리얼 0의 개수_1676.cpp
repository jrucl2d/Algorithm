#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	// 2 x 5�� ¦�� ����. �׷��� 2�� �ݵ�� �� �����Ƿ� 5�� ���� ���ϸ� ��.
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) {
			count++;
			if (i % 25 == 0) // 25�� ����� 5�� �� �� ��
				count++;
			if (i % 125 == 0) // 125�� ����� 5�� �� �� ��
				count++;
		}
	}
	cout<<count;
}