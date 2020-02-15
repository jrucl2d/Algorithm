#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 500 + 1

int t;
int k;
int dp[MAX][MAX];
int sum[MAX]; // 0���� i������ ��

// dp[i][j]�� i���� j������ �ּ� ����̶�� ����. 
// dp[i][i] = v[i], dp[i][i+1] = v[i] + v[i+1]�̴�.
// ��, dp[i][j]�� dp[i][mid] + dp[mid + 1][j]�� ��� ��� �� ���� �ּҰ��� 
// �������� i���� j������ ������ ����� �� ��� ��� sum[i - 1]~sum[j]�� �����ش�.

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> t;

	while (t-- > 0) {
		cin >> k;
		int tmp;
		vector<int> v;
		for (int i = 1; i <= k; i++) {
			cin >> tmp; v.push_back(tmp);
			sum[i] = sum[i - 1] + tmp; // 0���� �ش� �ε��������� ���� ��� �������.
		}

		for (int temp = 1; temp < k; temp++) {
			for (int i = 1; i <= k - temp; i++) {
				int j = i + temp;
				dp[i][j] = 1000000000; // ������ ū ���� �ʱ�ȭ

				for (int mid = i; mid < j; mid++) // i~j������ ���̹Ƿ� sum[j] - sum[i - 1]�� �´�.
					dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + sum[j] - sum[i - 1]);
			}
		}
		cout << dp[1][k] << "\n";
	}

}