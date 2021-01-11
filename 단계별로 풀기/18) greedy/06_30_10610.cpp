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
	// 3�� ����� ��� �ڸ����� ���ؼ� 3�� ����� �Ǿ�� �Ѵ�. 
	// �׸��� 30���� �����Ƿ� �ڸ� ���� 0�� �ϳ� �̻� �־�� �Ѵ�.
	// ����� ���ؼ� �� �����ʿ� 0�� �ΰ� �������� �׳� ��������
	for (int i = 0; i < num.length(); i++) {
		digit.push_back(num[i] - '0');
	}
	sort(digit.begin(), digit.end(), greater<int>()); // ��������
	int sum = 0;
	for (int i = 0; i < num.length(); i++)
		sum += digit[i];
	if (sum % 3 != 0 || digit.back() != 0) { // ���������̶� ���� 0 �־�� ��
		cout << -1;
	}
	else {
		for (int i = 0; i < num.length(); i++)
			cout << digit[i];
	}
}