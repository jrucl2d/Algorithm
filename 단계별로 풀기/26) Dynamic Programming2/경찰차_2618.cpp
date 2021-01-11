#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset 사용
using namespace std;

int n, w;
vector<pair<int, int>>v;
vector<int>ans;
int dp[1001][1001]; // 1번이 사건 i의 위치, 2번이 사건 j의 위치에 있을 때 거리 합의 최소
// 현재 m번째 사건을 처리해야 할 때
// 1번이 처리하면 dp[m][j] = dp[m - 1][j] + m과 그 전 사건의 거리차이
// 2번이 처리하면 dp[i][m] = dp[i][m - 1] +  m과 그 전 사건의 거리차이

int func(int first, int second) {
	if (first == w || second == w)
		return 0; // 탈출조건, 끝에 다다르면 종료

	int& tmp = dp[first][second]; // 현재의 상태
	if (tmp != -1) return tmp; // 해당 상태에 값이 존재하면 그 값 리턴(최초에 모든 dp를 -1로 초기화)

	 // 다음 상태는 현재 첫 번째와 두 번째 중 마지막으로 해결한 사건 번호 + 1번째 이다.
	int next = max(first, second) + 1; 
	int d1, d2;

	if (first == 0) // 처음 시작 시에는 현재 사건과 1번 경찰의 처음 위치(1,1)의 차이
		d1 = abs(v[next - 1].first - 1) + abs(v[next - 1].second - 1);
	else // 다음부터는 현재 사건과 1번 경찰의 현재 위치(v[first-1])의 차이
		d1 = abs(v[next - 1].first - v[first - 1].first) + abs(v[next - 1].second - v[first - 1].second);

	if (second == 0) 
		d2 = abs(v[next - 1].first - n) + abs(v[next - 1].second - n);
	else 
		d2 = abs(v[next - 1].first - v[second - 1].first) + abs(v[next - 1].second - v[second - 1].second);

	int case1 = func(next, second) + d1; // 1번 경찰이 다음 사건을 맡는 경우
	int case2 = func(first, next) + d2; // 2번 경찰이 다음 사건을 맡는 경우

	tmp = min(case1, case2); // 리턴할 값에 두 경우 중 최소값을 저장

	return tmp;
}

void print2(int first, int second) { // 과정을 출력, 이미 구한 식을 그대로 따라가며 과정을 저장
	if (first == w || second == w)
		return; // 탈출조건, 끝에 다다르면 종료


	 // 다음 상태는 현재 첫 번째와 두 번째 중 마지막으로 해결한 사건 번호 + 1번째 이다.
	int next = max(first, second) + 1;
	int d1, d2;

	if (first == 0) // 처음 시작 시에는 현재 사건과 1번 경찰의 처음 위치(1,1)의 차이
		d1 = abs(v[next - 1].first - 1) + abs(v[next - 1].second - 1);
	else // 다음부터는 현재 사건과 1번 경찰의 현재 위치(v[first-1])의 차이
		d1 = abs(v[next - 1].first - v[first - 1].first) + abs(v[next - 1].second - v[first - 1].second);

	if (second == 0)
		d2 = abs(v[next - 1].first - n) + abs(v[next - 1].second - n);
	else
		d2 = abs(v[next - 1].first - v[second - 1].first) + abs(v[next - 1].second - v[second - 1].second);

	int case1 = func(next, second) + d1; // 1번 경찰이 다음 사건을 맡는 경우
	int case2 = func(first, next) + d2; // 2번 경찰이 다음 사건을 맡는 경우

	if (case1 < case2) {
		ans.push_back(1);
		print2(next, second);
	}
	else {
		ans.push_back(2);
		print2(first, next);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n >> w;
	memset(dp, -1, sizeof(dp)); // dp배열 -1로 초기화

	int tmp1, tmp2;
	for (int i = 0; i < w; i++) {
		cin >> tmp1 >> tmp2;
		v.push_back({ tmp1,tmp2 });
	}
	cout << func(0, 0) << '\n'; // v를 처음부터 탐색
	print2(0, 0);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}