#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000

int cost[MAX][3];
int ans[MAX][3];

int func(int n) {
	ans[0][0] = cost[0][0];	ans[0][1] = cost[0][1];	ans[0][2] = cost[0][2];
	for (int i = 1; i < n; i++) {
		ans[i][0] = min(ans[i - 1][1], ans[i - 1][2]) + cost[i][0]; // 세 가지 경우에 대해서 계산
		ans[i][1] = min(ans[i - 1][0], ans[i - 1][2]) + cost[i][1];
		ans[i][2] = min(ans[i - 1][1], ans[i - 1][0]) + cost[i][2];
	}
	return min(min(ans[n - 1][0], ans[n - 1][1]), ans[n - 1][2]); // 최종 값 중 가장 작은 것 출력
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { // 정보 입력받기
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];
	}
	cout << func(n);
}