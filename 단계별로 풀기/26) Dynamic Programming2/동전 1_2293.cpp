#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// index i로 반복문을 돌면서 첫 번째 동전만 썼을 경우, 두 번째 동전도 썼을 경우, 세 번째 동전
// 까지 썼을 경우... 이런식으로 각각의 경우의 dp를 구한다. 이전 경우에서 구한 dp는 
// 다음에 dp를 구할 때 덮어씌어진다. 

int n, k;
vector<int>v;
int dp[10000 + 1]; // k를 만드는 경우의 수

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	cin >> n >> k;
	int tmp;
	v.push_back(0); // 1부터 index 시작하므로 채워준다.
	dp[0] = 1; // 0을 만드는 경우는 1개 있다.

	for (int i = 1; i <= n; i++) {
		cin >> tmp; v.push_back(tmp);
		for (int j = 1; j <= k; j++) {
			if (j >= v[i])
				dp[j] = dp[j] + dp[j - v[i]]; // 규칙성을 찾아야 한다.
		}
	}
	cout << dp[k];
}