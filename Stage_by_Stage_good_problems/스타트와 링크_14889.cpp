#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 20

int n;
int power[MAX][MAX];
bool visited[MAX];

int ans = 10000000;

void dfs(int start, int count) {
	if (count == n / 2) {
		vector <int> steam;
		vector <int> lteam;
		for (int i = 0; i < n; i++) {
			if (visited[i])
				steam.push_back(i); // 선택된 놈은 스타트 팀
			else lteam.push_back(i); // 나머지는 링크 팀
		}

		int spower = 0, lpower = 0;
		for (int i = 0; i < steam.size(); i++) {
			for (int j = i + 1; j < steam.size(); j++) {
				spower += power[steam[i]][steam[j]] + power[steam[j]][steam[i]]; // steam 파워 더함
				lpower += power[lteam[i]][lteam[j]] + power[lteam[j]][lteam[i]]; // lteam 파워 더함
			}
		}
		ans = min(ans, abs(spower - lpower)); // 차이 최소값 구함
		return;
	}
	for (int i = start; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, count + 1);
			visited[i] = false;
		}
	}

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// 정보 입력 받기
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> power[i][j];
	dfs(0, 0);
	cout << ans;
}