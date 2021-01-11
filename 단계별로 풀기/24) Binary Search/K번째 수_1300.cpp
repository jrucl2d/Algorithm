#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n;
ll k;
// ���� Ŀ������ ó���� �࿡ *���� �ϴ� ���·� ���ڰ� ����ȴ�.
// ���� mid ���� ���� ���� ������ mid/�� ���� ���� �� �ִ�.
// ���⿡ ���� ������ ���� Ŀ���� ��찡 �����Ƿ� min(mid/i,n)���� �ۼ��Ѵ�.

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> k;
	ll left = 1;
	ll right = k;
	ll count = 0;
	ll ans = 0;
	while (left <= right) {
		count = 0;
		ll mid = (left + right) / 2;
		for (int i = 1; i <= n; i++) { // �ึ�� mid���� ���� ���� count�Ѵ�.
			count += min(mid / i, n);
		}
		if (count < k) left = mid + 1; // ��� ���� �� ������ ������(�� ū ��) Ž��
		else { // ��� ���� �� ũ�ٸ� �� ���� �� Ž��
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;
}