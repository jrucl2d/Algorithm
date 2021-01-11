#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000

int arr[MAX];
int n;
int dp[MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1; // ���ʿ� �ڱ� �ڽ� �ֱ�
		for (int j = 0; j < i; j++) { // �ڽ� ���� �� �߿���
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) { // ���� �ڽ��� �������� ���� �Ϳ� �ڱ� �ڽ��� ���� ���� �� ũ��
				dp[i] = dp[j] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}