#include <iostream> 
#include <algorithm>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	// n과 m이 비슷하면 n+m-k/3 -> 모든 인원(n+m-k)를 남 여 1:2의 비율로 나눠야 하므로
	// n이 크면 n+m-k/3과 m을 비교
	// m이 크면 n+m-k/3과 n/2를 비교
	cout << min(min((n + m - k) / 3, m), n / 2);
}
