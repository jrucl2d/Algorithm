#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 300 + 1

int n;
int stair[MAX];
int ans[MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> stair[i];
	
	ans[1] = stair[1];
	ans[2] = max(stair[2], stair[1] + stair[2]);
	for (int i = 3; i <= n; i++) {
		// ������ ���� ���� ������Ƿ� ���� ���� �� ��� ������ ���� ��Ҵ�.
		// ������ ���� ���� �� ������Ƿ� ���� ���� ��Ҵ�. �� �� ū ������ ���Ѵ�.
		ans[i] = max(stair[i] + stair[i - 1] + ans[i - 3], stair[i] + ans[i - 2]);
	}
	cout << ans[n];
}