#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2000 + 1

int n, m;
int arr[MAX];
int dp[MAX][MAX]; // i부터 j까지 팰린드롬이면 1을 저장, 아니면 0 저장.

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	cin >> m;
	int s, e;

	// 사전 작업
	for (int i = 1; i <= n; i++) // 길이가 1 : 처음과 끝이 같으면 팰린드롬
		dp[i][i] = 1;
	for (int i = 1; i <= n - 1; i++) // 길이가 2 : 수가 두 개이고, 두 수가 같으면 팰린드롬
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1;

	for (int intev = 3; intev <= n; intev++) { // 간격
		for (int i = 1; i <= n - intev + 1; i++) { // 예로, n이 8이면 최소 간격 3일 때 i가 6까지이므로 8 - 3 + 1
			int j = i + intev - 1;
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1)	// 길이가 3 : 끝단이 같고, 그 안이 팰린드롬이면 팰린드롬
				dp[i][j] = 1;
		}
	}

	vector<int>ans;
	while (m-- > 0) {
		cin >> s >> e;
		ans.push_back(dp[s][e]);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}