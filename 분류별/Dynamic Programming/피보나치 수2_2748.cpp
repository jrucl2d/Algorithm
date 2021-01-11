#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long arr[90]; // 90보다 작거나 같은 자연수, 90 넣으면 int 범위 벗어나므로 long long 써야 함

long long func(int a) { // 피보나치
	if (arr[a] == 0) { // 구해야 할 수가 비어있으면 계산
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