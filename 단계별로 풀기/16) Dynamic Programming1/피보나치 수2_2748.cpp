#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long arr[90]; // 90���� �۰ų� ���� �ڿ���, 90 ������ int ���� ����Ƿ� long long ��� ��

long long func(int a) { // �Ǻ���ġ
	if (arr[a] == 0) { // ���ؾ� �� ���� ��������� ���
		for (int i = 2; i <= n; i++) {
			arr[i] = arr[i - 2] + arr[i - 1];
		}
		return arr[a];
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	arr[0] = 0; arr[1] = 1;
	cout << func(n);
}