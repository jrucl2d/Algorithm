#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// index i�� �ݺ����� ���鼭 ù ��° ������ ���� ���, �� ��° ������ ���� ���, �� ��° ����
// ���� ���� ���... �̷������� ������ ����� dp�� ���Ѵ�. ���� ��쿡�� ���� dp�� 
// ������ dp�� ���� �� ���������. 

int n, k;
vector<int>v;
int dp[10000 + 1]; // k�� ����� ����� ��

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	cin >> n >> k;
	int tmp;
	v.push_back(0); // 1���� index �����ϹǷ� ä���ش�.
	dp[0] = 1; // 0�� ����� ���� 1�� �ִ�.

	for (int i = 1; i <= n; i++) {
		cin >> tmp; v.push_back(tmp);
		for (int j = 1; j <= k; j++) {
			if (j >= v[i])
				dp[j] = dp[j] + dp[j - v[i]]; // ��Ģ���� ã�ƾ� �Ѵ�.
		}
	}
	cout << dp[k];
}