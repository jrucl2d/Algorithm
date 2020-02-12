#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m;
vector<int>v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> m;
	ll tmp;
	ll limit = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
		limit = max(limit, tmp); // ������ �ִ��� ã�´�.
	}
	ll left = 0; ll right = limit; ll mid = 0;
	ll ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if(v[i] >= mid)
				sum += (v[i] - mid); // ���̸� ��� ���غ���.
		}	
		if (sum >= m) { // ���̰� �ʹ� ũ�� �� ���� �߶󺻴�.
			ans = max(ans, mid); // ans���� ���ο� mid�� ���ؼ� �� ū ���� �����ؾ� �Ѵ�.
			left = mid + 1;
		}		
		else 
			right = mid - 1; // ���̰� ������ �� ���� �߶󺻴�.
	}
	cout << ans;
}