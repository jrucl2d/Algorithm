#include <iostream>
#include <string>
using namespace std;

int main() {
	int first;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> first;
	int rotate = first;
	int count = 0;
	while (true) {
		int add = (rotate / 10 + rotate % 10) % 10; // 각 자리수 더한 것의 1의 자리
		rotate = (rotate % 10) * 10 + add; // 새로운 숫자
		count++;
		if (rotate == first)
			break;
	}
	cout << count;
}
