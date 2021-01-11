#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000

vector<int>v;
int dp[MAX]; // 해당 인덱스에 자기까지의 최고 길이 저장
int dp2[MAX]; // 거꾸로 해당 인덱스에 자기까지의 최고 길이 저장

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
	// 순서대로 LIS
	for (int i = 0; i < n; i++) {
		dp[i] = 1; // 자기 자신
		for (int j = 0; j <= i; j++)
			if (v[i] > v[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
	}
	// 거꾸로 LIS
	for (int i = n - 1; i >= 0; i--) {
		dp2[i] = 1; // 자기 자신
		for (int j = n - 1; j >= i; j--)
			if (v[i] > v[j] && dp2[j] + 1 > dp2[i])
				dp2[i] = dp2[j] + 1;
	}
	int max = 0;
	for (int i = 0; i < n; i++) { // 두 길이를 더하면 해당 인덱스가 최고일 때 총 길이 + 1
		if (max < dp[i] + dp2[i])
			max = dp[i] + dp2[i];
	}
	cout << max - 1; // 자기 자신 포함
}