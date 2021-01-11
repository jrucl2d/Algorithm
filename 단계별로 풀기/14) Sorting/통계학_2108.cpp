#include <iostream> // 카운팅(계수)정렬
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cnt[8001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int tmp;
	int sum = 0;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		cnt[tmp + 4000]++;
		v.push_back(tmp);
	}
	// 산술 평균
	double avg = (double)sum / n;
	cout << round(avg) << '\n'; // 반올림
	// 중앙값
	sort(v.begin(), v.end());
	cout << v[v.size() / 2] << '\n';
	// 최빈값
	int wantIndex = -1;
	int wantMax = 0;
	bool second = false; // 두 번째를 파악
	for (int i = 0; i <= 8000; i++) 
		wantMax = max(wantMax, cnt[i]); // wantMax를 찾는 과정
	for (int i = 0; i <= 8000; i++) { // 비교 및 두 번째 것 찾기
		if (wantMax == cnt[i]) {
			wantIndex = i;
			if(second)
				break;
			second = true;
		}
	}
	cout << wantIndex - 4000 << '\n';
	// 범위
	cout << v.back() - v.front() << '\n';
}