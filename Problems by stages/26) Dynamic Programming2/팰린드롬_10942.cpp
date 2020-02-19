#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2000 + 1

int n, m;
int arr[MAX];
int dp[MAX][MAX]; // i���� j���� �Ӹ�����̸� 1�� ����, �ƴϸ� 0 ����.

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	cin >> m;
	int s, e;

	// ���� �۾�
	for (int i = 1; i <= n; i++) // ���̰� 1 : ó���� ���� ������ �Ӹ����
		dp[i][i] = 1;
	for (int i = 1; i <= n - 1; i++) // ���̰� 2 : ���� �� ���̰�, �� ���� ������ �Ӹ����
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1;

	for (int intev = 3; intev <= n; intev++) { // ����
		for (int i = 1; i <= n - intev + 1; i++) { // ����, n�� 8�̸� �ּ� ���� 3�� �� i�� 6�����̹Ƿ� 8 - 3 + 1
			int j = i + intev - 1;
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1)	// ���̰� 3 : ������ ����, �� ���� �Ӹ�����̸� �Ӹ����
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