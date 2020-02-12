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
		limit = max(limit, tmp); // 높이의 최댓값을 찾는다.
	}
	ll left = 0; ll right = limit; ll mid = 0;
	ll ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if(v[i] >= mid)
				sum += (v[i] - mid); // 차이를 모두 더해본다.
		}	
		if (sum >= m) { // 차이가 너무 크면 더 많이 잘라본다.
			ans = max(ans, mid); // ans에는 새로운 mid와 비교해서 더 큰 값을 저장해야 한다.
			left = mid + 1;
		}		
		else 
			right = mid - 1; // 차이가 작으면 더 적게 잘라본다.
	}
	cout << ans;
}