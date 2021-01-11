#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int sugar;
	cin >> sugar;
	int n = sugar / 3;
	int m = sugar / 5;
	int minN = 100000;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			if (i * 3 + j * 5 == sugar) { // �ּҸ� ã��
				minN = min(minN, i + j);
			}
		}
	}
	if (minN == 100000) cout << -1; // minN�� �ٲ��� �ʾ����� �� ã����
	else cout << minN;
}