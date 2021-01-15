#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 1000000000
typedef long long ll;

// ax + by = c => as + bt = r을 만족하는 s, t, r조합을 찾기(r이 gcd(a, b)일 때)
vector<int> eGcd(int a, int b) {                                                                          
	int s0 = 1, t0 = 0, r0 = a; // 표 첫 번재 줄
	int s1 = 0, t1 = 1, r1 = b; // 표 두 번째 줄
	
	int tmp;
	while (r1 != 0) { // r1이 0일 때 r0가 gcd(a, b)가 될 것이다. 
		int q = r0 / r1;

		tmp = r0 - q * r1; // 새로운 r 값
		r0 = r1; // 아래로 한 칸 shift
		r1 = tmp;

		tmp = s0 - q * s1;
		s0 = s1;
		s1 = tmp;

		tmp = t0 - q * t1;
		t0 = t1;
		t1 = tmp;
	}
	vector<int>v;
	v.push_back(s0);
	v.push_back(t0);
	v.push_back(r0);
	return v;
}

int t;
int a, b;

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		// x : 인당 나눠줄 사탕의 수
		// y : 사탕 봉지의 수
		// Ax + By = C 형태로 변환
		// A * x + 1 = B * y -> -Ax + By = 1 -> A(-x) + By = 1 
		// D = gcd(A, B)
		// D * k = C -> C % D == 0 이여야만 해를 가질 수 있다. -> 배주 항등식
		// 확장 유클리드 호제법을 이용하여 s, t, (r = D)를 찾아냄

		vector<int>res = eGcd(a, b);
		int s = res[0], t = res[1], d = res[2];
		if (d != 1) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		// x0 = s * C/D
		int x0 = s; // c도 1이고 d도 1이다.
		// y0 = t * C/D
		int y0 = t;

		// 일반 해 공식
		// x = x0 + B/D * k
		// y = y0 - A/D * k
		int k;

		// 0 > x 원래 x > 0이지만 위에서 식에서 x를 -x로 바꿨으므로 0보다 작은 x를 구해야 함
		// x0 + B/D * k < 0
		// k만 모르므로 k에 대해서 정리하면
		// k < -x0 / B * D
		ll upper = ll(ceil((double)-x0 / b)) - 1;

		// 0 < y <= 1e9
		// 0 < y0 - A/D * k <= 1e9
		// -y0 <= -A/D * k < 1e9 -y0
		// (y0 - 1e9) / A * D <= k < y0 / A * D
		upper = min(upper, ll(ceil((double)y0 / a)) - 1);

		// 저 범위를 만족하는 k의 max를 구한 후에 그 k를 이용해서 y값을 구해내고 -> k가 커질수록 y가 작아짐
		// 구한 y는 가장 작은 y값.
		// 그 구한 y값이 1e9보다 작거나 같다면 가능한 답
		// 아니면 불가능한 답
		ll y = y0 - (a / d) * upper;
		if (y <= MAX) {
			cout << y << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}