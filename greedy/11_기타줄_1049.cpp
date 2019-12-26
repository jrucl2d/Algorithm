#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<pair<int, int>>strings;
	int n, m; // n은 끊긴 줄 수, m은 브랜드 수
	cin >> n >> m;
	int tmp1, tmp2;
	int minSet = 1000; // 세트 중 가장 싼 가격
	int minOnly = 1000; // 낱개 중 가장 싼 가격
	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> tmp2;
		minSet = min(minSet, tmp1);
		minOnly = min(minOnly, tmp2);
		strings.push_back(make_pair(tmp1, tmp2));
	}
	if (n < 6) { // n이 6 이하이면 세트 하나와 낱개 비교
		cout << min(minSet, minOnly * n);
	}
	else { // n이 6 이상이고
		if (n % 6 == 0) // 6으로 나누어 떨어지면 세트와 낱개 비교 
			cout << min(minSet * (n / 6), minOnly * n);
		else { // 6으로 안 나누어 떨어지면
			// 최대한 패키지 가격으로 싸게 사고 나머지는 낱개로 구매, 낱개 구매 비교
			int minNum1 = min(minSet * (n / 6) + minOnly * (n % 6), minOnly * n);
			// 모두 패키지 가격으로 샀을 때
			int minNum2 = minSet * (n / 6 + 1);
			cout << min(minNum1, minNum2);
		}
	}
}