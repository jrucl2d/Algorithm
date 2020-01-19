#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	// 2 x 5의 짝의 개수. 그런데 2가 반드시 더 많으므로 5의 개수 구하면 됨.
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) {
			count++;
			if (i % 25 == 0) // 25의 배수는 5가 두 개 들어감
				count++;
			if (i % 125 == 0) // 125의 배수는 5가 세 개 들어감
				count++;
		}
	}
	cout<<count;
}