#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000

vector<int>v;
int dp[MAX]; // �ش� �ε����� �ڱ������ �ְ� ���� ����
int dp2[MAX]; // �Ųٷ� �ش� �ε����� �ڱ������ �ְ� ���� ����

int n;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int tmp;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	// ������� LIS
	for (int i = 0; i < n; i++) {
		dp[i] = 1; // �ڱ� �ڽ�
		for (int j = 0; j <= i; j++)
			if (v[i] > v[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
	}
	// �Ųٷ� LIS
	for (int i = n - 1; i >= 0; i--) {
		dp2[i] = 1; // �ڱ� �ڽ�
		for (int j = n - 1; j >= i; j--)
			if (v[i] > v[j] && dp2[j] + 1 > dp2[i])
				dp2[i] = dp2[j] + 1;
	}
	int max = 0;
	for (int i = 0; i < n; i++) { // �� ���̸� ���ϸ� �ش� �ε����� �ְ��� �� �� ���� + 1
		if (max < dp[i] + dp2[i])
			max = dp[i] + dp2[i];
	}
	cout << max - 1; // �ڱ� �ڽ� ����
}