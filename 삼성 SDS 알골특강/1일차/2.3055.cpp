#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int main() {
	int r, c;
	vector<string> arr;
	vector<vector<int>> dp;
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	queue<pair<int, int>> boy;
	queue<pair<int, int>> water;

	int dest[2] = { 0, 0 };

	cin >> r >> c;

	// dp 초기화
	for (int i = 0; i < r; i++) {
		vector<int> tmp;
		for (int j = 0; j < c; j++) {
			tmp.push_back(-1);
		}
		dp.push_back(tmp);
		tmp.clear();
	}

	for (int i = 0; i < r; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < c; j++) {
			if (tmp[j] == 'S') {
				boy.push({ i, j });
				dp[i][j] = 0;
			}
			else if (tmp[j] == '*') {
				water.push({ i, j });
			}
			else if (tmp[j] == 'D') {
				dest[0] = i;
				dest[1] = j;
			}
		}
		arr.push_back(tmp);
	}
	
	int time = 0;
	// 큐
	while (!boy.empty()) {
		// 물 이동
		queue<pair<int, int>> tmp;
		while (!water.empty()) {
			pair<int, int> tmpWater = water.front();
			water.pop();
			for (int i = 0; i < 4; i++) {
				int nx = tmpWater.first + dx[i];
				int ny = tmpWater.second + dy[i];
				if (nx >= 0 && ny >= 0 && nx < r && ny < c && arr[nx][ny] != '*' && arr[nx][ny] != 'D' && arr[nx][ny] != 'X' ) {
					arr[nx][ny] = '*';
					tmp.push({ nx,ny });
				}
			}
		}
		while (!tmp.empty()) {
			water.push(tmp.front());
			tmp.pop();
		}
		// 고슴도치 이동
		while (!boy.empty()) {
			pair<int, int> tmpboy = boy.front();
			boy.pop();
			if (tmpboy.first == dest[0] && tmpboy.second == dest[1]) {
				cout << time << endl;
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nx = tmpboy.first + dx[i];
				int ny = tmpboy.second + dy[i];
				if (nx >= 0 && ny >= 0 && nx < r && ny < c && arr[nx][ny] != '*' && arr[nx][ny] != 'X' && dp[nx][ny] == -1) {
					dp[nx][ny] = time;
					tmp.push({ nx,ny });
				}
			}
		}
		time += 1;

		while (!tmp.empty()) {
			boy.push(tmp.front());
			tmp.pop();
		}
	}

	cout << "KAKTUS" << endl;

	return 0;
}