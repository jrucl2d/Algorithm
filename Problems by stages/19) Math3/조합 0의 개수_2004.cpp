#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// ���� ������ ũ�Ƿ� long long ��� �ʼ�
long long find5(long long n) { // �ð� ���⵵�� �� ���� Ǯ��
	long long count = 0;
	for (long long i = 5; i <= n; i *= 5) {
		count += n / i; // 5�� ��������, 25�� ��������...
	}
	return count;
}
long long find2(long long n) {
	long long count = 0;
	for (long long i = 2; i <= n; i *= 2) {
		count += n / i;
	}
	return count;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long a, b;
	cin >> a >> b;
	long long ans = min(find2(a) - find2(b) - find2(a - b), find5(a) - find5(b) - find5(a - b));
	cout << ans;
}