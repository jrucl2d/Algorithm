#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 숫자 범위가 크므로 long long 사용 필수
long long find5(long long n) { // 시간 복잡도가 더 낮은 풀이
	long long count = 0;
	for (long long i = 5; i <= n; i *= 5) {
		count += n / i; // 5로 나눠보고, 25로 나눠보고...
	}
	return count;
}
long long find2(long long n) {
	long long count = 0;
	for (long long i = 2; i <= n; i *= 2) {
		count += n / i;
	}
	return count;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long a, b;
	cin >> a >> b;
	long long ans = min(find2(a) - find2(b) - find2(a - b), find5(a) - find5(b) - find5(a - b));
	cout << ans;
}