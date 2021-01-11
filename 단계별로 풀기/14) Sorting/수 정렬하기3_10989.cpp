#include <iostream> // 카운팅(계수)정렬
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10001 //10,000보다 작거나 같으므로
int cnt[MAX];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int tmp;
	while (n-- > 0) {
		cin >> tmp;
		cnt[tmp]++; // 등장 숫자의 횟수를 증가
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < cnt[i]; j++)
			cout << i << '\n'; // i가 존재하면 그 횟수만큼 출력
	}
}