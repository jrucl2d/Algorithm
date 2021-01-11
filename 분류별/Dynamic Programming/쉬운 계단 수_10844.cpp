#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 100 + 1
#define Mod 1000000000

int n;
int dp[MAX][10]; // 총 자리수, 마지막자리 숫자, i 자릿수의 숫자 중 j로 끝나는 수.
// i자리 수 중 j로 끝나는 수는 i-1자리 수 중 j-1로 끝나는 수와 j+1로 끝나는 수의 합
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1; // 0으로 시작하는 숫자가 없으므로
	}
	for (int i = 2; i <= n; i++) { 
		for (int j = 0; j <= 9; j++) {
			// i자리 수 중 0으로 끝나는 수들은 i-1자리 수 중 1로 끝나는 수에서만 올 수 있다.
			if (j == 0) dp[i][j] = dp[i - 1][1] % Mod; 
			else if (j == 9) dp[i][j] = dp[i - 1][8] % Mod; // 8에서만 올 수 있다.
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % Mod;
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[n][i]) % Mod;
	}
	cout << sum % Mod;
}