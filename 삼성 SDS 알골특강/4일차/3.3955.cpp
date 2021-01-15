#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 1000000000
typedef long long ll;

// ax + by = c => as + bt = r�� �����ϴ� s, t, r������ ã��(r�� gcd(a, b)�� ��)
vector<int> eGcd(int a, int b) {                                                                          
	int s0 = 1, t0 = 0, r0 = a; // ǥ ù ���� ��
	int s1 = 0, t1 = 1, r1 = b; // ǥ �� ��° ��
	
	int tmp;
	while (r1 != 0) { // r1�� 0�� �� r0�� gcd(a, b)�� �� ���̴�. 
		int q = r0 / r1;

		tmp = r0 - q * r1; // ���ο� r ��
		r0 = r1; // �Ʒ��� �� ĭ shift
		r1 = tmp;

		tmp = s0 - q * s1;
		s0 = s1;
		s1 = tmp;

		tmp = t0 - q * t1;
		t0 = t1;
		t1 = tmp;
	}
	vector<int>v;
	v.push_back(s0);
	v.push_back(t0);
	v.push_back(r0);
	return v;
}

int t;
int a, b;

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		// x : �δ� ������ ������ ��
		// y : ���� ������ ��
		// Ax + By = C ���·� ��ȯ
		// A * x + 1 = B * y -> -Ax + By = 1 -> A(-x) + By = 1 
		// D = gcd(A, B)
		// D * k = C -> C % D == 0 �̿��߸� �ظ� ���� �� �ִ�. -> ���� �׵��
		// Ȯ�� ��Ŭ���� ȣ������ �̿��Ͽ� s, t, (r = D)�� ã�Ƴ�

		vector<int>res = eGcd(a, b);
		int s = res[0], t = res[1], d = res[2];
		if (d != 1) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		// x0 = s * C/D
		int x0 = s; // c�� 1�̰� d�� 1�̴�.
		// y0 = t * C/D
		int y0 = t;

		// �Ϲ� �� ����
		// x = x0 + B/D * k
		// y = y0 - A/D * k
		int k;

		// 0 > x ���� x > 0������ ������ �Ŀ��� x�� -x�� �ٲ����Ƿ� 0���� ���� x�� ���ؾ� ��
		// x0 + B/D * k < 0
		// k�� �𸣹Ƿ� k�� ���ؼ� �����ϸ�
		// k < -x0 / B * D
		ll upper = ll(ceil((double)-x0 / b)) - 1;

		// 0 < y <= 1e9
		// 0 < y0 - A/D * k <= 1e9
		// -y0 <= -A/D * k < 1e9 -y0
		// (y0 - 1e9) / A * D <= k < y0 / A * D
		upper = min(upper, ll(ceil((double)y0 / a)) - 1);

		// �� ������ �����ϴ� k�� max�� ���� �Ŀ� �� k�� �̿��ؼ� y���� ���س��� -> k�� Ŀ������ y�� �۾���
		// ���� y�� ���� ���� y��.
		// �� ���� y���� 1e9���� �۰ų� ���ٸ� ������ ��
		// �ƴϸ� �Ұ����� ��
		ll y = y0 - (a / d) * upper;
		if (y <= MAX) {
			cout << y << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}