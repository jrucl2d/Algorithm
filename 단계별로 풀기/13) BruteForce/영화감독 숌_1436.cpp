#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int first = 666;
	int count = 1;
	while (true) {
		if (n == count) // count�� ���ϴ� n�� ��ġ�ϸ� �ݺ� Ż��
			break;
		first++;
		string tmp = to_string(first);
		if (tmp.find("666") >= 0 && tmp.find("666") <= tmp.size() - 1) count++; // 666�� ���ӵ� ���� count ����
	}
	cout << first;
}