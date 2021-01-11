#include <iostream>
#include <vector>
#include <string>
using namespace std;
int result(int n) {
	// 입력받은 수로 생성한 D(n)을 출력
	string s = to_string(n);
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
		sum += (s[i] - '0');
	sum += n;
	return sum;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	bool not_self[10001] = { false, };
	for (int i = 1; i < 10001; i++) {
		int tmp = result(i);
		if(tmp <= 10000)
			not_self[tmp] = true; // self가 아닌 것 체크
	}
	for (int i = 1; i <= 10000; i++) {
		if (!not_self[i])
			printf("%d\n", i);
	}
}