#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	vector<int>digit;
	string num;
	cin >> num;
	// 3의 배수는 모든 자리수를 더해서 3의 배수가 되어야 한다. 
	// 그리고 30으로 나누므로 자리 내에 0이 하나 이상 있어야 한다.
	// 출력을 위해서 맨 오른쪽에 0을 두고 나머지는 그냥 내림차순
	for (int i = 0; i < num.length(); i++) {
		digit.push_back(num[i] - '0');
	}
	sort(digit.begin(), digit.end(), greater<int>()); // 내림차순
	int sum = 0;
	for (int i = 0; i < num.length(); i++)
		sum += digit[i];
	if (sum % 3 != 0 || digit.back() != 0) { // 내림차순이라 끝에 0 있어야 함
		cout << -1;
	}
	else {
		for (int i = 0; i < num.length(); i++)
			cout << digit[i];
	}
}