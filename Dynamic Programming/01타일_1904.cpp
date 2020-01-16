#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long arr[1000001];

long long func(int a) { // 1�� Ƚ���� ���� ��, 0�� ���� ���� ���̴�. (1�� n��°�̸� 0�� n-1�� °)
    for (int i = 3; i <= a; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 15746; // ���� ���� �ִ´�.
    }
	return arr[a];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
    arr[1] = 1; arr[2] = 2;

	int n;
	cin >> n;
	cout << func(n);
	
}