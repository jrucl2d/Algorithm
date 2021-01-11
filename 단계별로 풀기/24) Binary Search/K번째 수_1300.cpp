#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n;
ll k;
// 열이 커질수록 처음의 행에 *열을 하는 형태로 숫자가 저장된다.
// 따라서 mid 보다 작은 수의 개수는 mid/행 으로 구할 수 있다.
// 여기에 열의 수보다 몫이 커지는 경우가 있으므로 min(mid/i,n)으로 작성한다.

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
		for (int i = 1; i <= n; i++) { // 행마다 mid보다 작은 수를 count한다.
			count += min(mid / i, n);
		}
		if (count < k) left = mid + 1; // 세어본 것이 더 작으면 오른쪽(더 큰 쪽) 탐색
		else { // 세어본 것이 더 크다면 더 작은 쪽 탐색
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;
}