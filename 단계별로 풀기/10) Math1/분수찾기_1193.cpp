#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a;
	cin >> a;
	int count = 1;
	int sum = 3;
	int how; // �󸶳� ������ �ִ���
	while (true) {
		if (a <= sum) {
			how = sum - a;
			break;
		}
		sum += (4 * ++count) - 1;
	}
	int below = count * 2;
	if (below >= how + 1) { // 1/n�� �������� ������
		cout << below - how << "/" << 1 + how;
	}
	else { // 1/n�� �������� ����
		cout << 1 + how - below << "/" << below - (how - below + 1);
	}
}