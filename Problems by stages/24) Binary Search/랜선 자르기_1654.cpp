#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
ll k, n;
vector<ll>v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> k >> n;
	ll tmp;
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	ll left = 0; ll right = LLONG_MAX; // 2�� 31 - 1���� ������ ����
	ll mid = 0;
	ll ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < k; i++) 
			sum += v[i] / mid;
		if (sum < n) { // ���� ���ϴ� ���� �������� ���ٸ�
			right = mid - 1;
		}
		else {
			left = mid + 1;
			ans = max(ans, mid);
		}
	}
	cout << ans;
}