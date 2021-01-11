#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
/// 최대한 빨리 끝나는 놈부터 처리 <-- 빨리 끝나는 순으로 정렬 필요
/// 끝과 겹치지 않는 놈으로 계속 이어 붙임
int main() {
	vector<pair<int, int>>set;
	int conferenceNum;
	cin >> conferenceNum;
	int tmp1, tmp2;
	for (int i = 0; i < conferenceNum; i++) {
		cin >> tmp1 >> tmp2;
		set.push_back(make_pair(tmp2, tmp1)); // tmp2(끝나는 시간)로 정렬
	}
	sort(set.begin(), set.end());
	int end = set[0].first;
	int count = 1;
	for (int i = 1; i < conferenceNum; i++) {
		if (set[i].second >= end) { // 다음 시작 주소가 끝보다 커야만
			count++;
			end = set[i].first; // end를 갱신
		}
	}
	cout << count;
}
