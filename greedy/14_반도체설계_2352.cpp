#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// LIS 문제
int main() {
	vector<int>link;
	vector<int>lis;
	int num;
	scanf("%d", &num); // 포트 수
	int tmp;
	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		link.push_back(tmp);
	}
	lis.push_back(link[0]); // 첫 요소 집어넣기
	for (int i = 1; i < num; i++) {
		if (lis.back() < link[i]) {// link의 현재 값이 lis의 마지막 값보다 크면
			lis.push_back(link[i]); // 현재 값을 lis에 추가
		}
		else { // link의 현재 값이 lis의 마지막 값보다 작으면 교체
			auto it = lower_bound(lis.begin(), lis.end(), link[i]);
			*it = link[i];
		}
		/*for (int i = 0; i < lis.size(); i++)
			cout << lis[i] << " ";
		cout << endl;*/
	}
	cout << lis.size(); // lis의 사이즈를 리턴
}