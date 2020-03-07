#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000 + 1
#define INF 1000000
int cost[MAX][3]; // i��° ���� j�� ����� ĥ�� �� ��� ���
int dp[MAX][3]; 

int n;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];
	}
	int ans = INF;
	for (int color = 0; color < 3; color++) { // �� �� �ݺ�
		for (int i = 0; i < 3; i++) { // ���� color ���� �����̸�
			if (i == color) dp[0][i] = cost[0][i]; // �ش� dp[0]�� color������ ĥ�ϰ�
			else dp[0][i] = INF; // �������� INF�� �ʱ�ȭ. min���� �Ÿ��Ƿ� ù��°�� ������ color���� ĥ�� ���� ��.
		}
		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0]; // �� ���� ��쿡 ���ؼ� ���
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[i][2];
		}
		for (int i = 0; i < 3; i++) {
			if (i == color) continue; // ù ������ color�̹Ƿ� �� ������ color�� ���� ����.
			else ans = min(ans, dp[n - 1][i]);
		}
	}
	cout << ans;
}