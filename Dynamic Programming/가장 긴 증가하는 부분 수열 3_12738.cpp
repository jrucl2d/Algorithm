#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000000

int arr[MAX];
int n;
vector<int> dp;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//int dp[MAX];
	//cin >> n;
	//for (int i = 0; i < n; i++) {
	//	cin >> arr[i];
	//	dp[i] = 1; // ���ʿ� �ڱ� �ڽ� �ֱ�
	//	for (int j = 0; j < i; j++) { // �ڽ� ���� �� �߿���
	//		if (arr[i] > arr[j] && dp[i] < dp[j] + 1) { // ���� �ڽ��� �������� ���� �Ϳ� �ڱ� �ڽ��� ���� ���� �� ũ��
	//			dp[i] = dp[j] + 1;
	//		}
	//	}
	//}
	//int ans = 0;
	//for (int i = 0; i < n; i++)
	//	ans = max(ans, dp[i]);
	// ������ O(n^2)�� ��
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp.push_back(arr[0]); // ù ��� ���� �ֱ�
	for (int i = 1; i < n; i++) {
		if (dp.back() < arr[i]) {
			dp.push_back(arr[i]);
		}
		else {
			auto it = lower_bound(dp.begin(), dp.end(), arr[i]); // lower_bound ����
			*it = arr[i];
		}
	}
	cout << dp.size();
}