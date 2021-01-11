#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, c;
vector<int>place;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> c;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp; place.push_back(tmp);
	}
	sort(place.begin(), place.end());

	int left = 1; // 가능한 최소 거리 1
	int right = place[n - 1] - place[0]; // 가능한 최대 거리
	int mid = 0;
	int ans = 0; 
	int count = 1; // 첫 번째에 공유기를 이미 설치하고 시작한다.
	while (left <= right) { // 등호가 들어가는 이유는 최단거리 중 최대를 찾기 위해서.
		mid = (left + right) / 2;
		count = 1; 
		int start = place[0]; // 첫 번째가 시작점

		// 현재 mid 값이 최소 간격이므로 첫 번째부터 시작해서 최소 간격 떨어진 곳에 공유기 설치
		// 새로 설치하면 시작 장소를 그곳으로 다시 갱신해서 또 최소 간격 떨어진 곳에 설치
		for (int i = 1; i < n; i++) {
			if (place[i] - start >= mid) {
				start = place[i];
				count++;
			}
		}
		if (count >= c) { // 설치 가능 횟수보다 더 많이 설치했다.
			ans = mid; // 현재의 mid 값을 최단거리 중 최대로 가정.
			left = mid + 1; // 더 최대가 존재하는지 검색
		}
		else right = mid - 1; // 설치 가능 횟수보다 더 적으면 더 작은 간격에서 찾음
	}
	cout << ans;
}