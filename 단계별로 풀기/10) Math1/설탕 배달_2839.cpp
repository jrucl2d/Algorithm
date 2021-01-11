#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int sugar;
	cin >> sugar;
	int n = sugar / 3;
	int m = sugar / 5;
	int minN = 100000;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			if (i * 3 + j * 5 == sugar) { // 최소를 찾음
				minN = min(minN, i + j);
			}
		}
	}
	if (minN == 100000) cout << -1; // minN가 바뀌지 않았으면 못 찾은것
	else cout << minN;
}