#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
#define MAX  500 + 1

// dp[i][j]는 중간의 k를 기점으로 dp[i][k] + dp[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1]
// 의 식으로 구할 수 있다. 뒤에 더해주는 부분은 첫 행렬의 행, 가운데 행렬의 열, 마지막 행렬의 열을
// 곱해야 하기 때문이다.

int dp[MAX][MAX]; // i에서 j까지 곱할 때의 최소값
int matrix[MAX][2]; // 0에는 행, 1에는 열이 들어간다.

int n;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) { // 행과 열을 순서대로 입력받음
		cin >> matrix[i][0] >> matrix[i][1];
	}
	for (int i = 1; i < n; i++) // 차이가 하나 나는 경우는 두 개 그냥 곱해준다.
		dp[i][i + 1] = matrix[i][0] * matrix[i][1] * matrix[i + 1][1];

	for (int tmp = 2; tmp < n; tmp++) { // 둘 사이의 차이
		for (int i = 1; i <= n - tmp; i++) { // i는 1부터 n - 1까지
			int j = tmp + i; // j는 2부터 n까지
			dp[i][j] = INT_MAX;
			for (int mid = i; mid < j; mid++) {
				// dp[i][j]를 모든 중간값 mid에 대해서 구해본다. 그 중 가장 작은 값으로 설정
				dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + matrix[i][0] * matrix[mid][1] * matrix[j][1]);
			}
		}
	}
	cout << dp[1][n] << "\n";
}