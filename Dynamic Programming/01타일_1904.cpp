#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long arr[1000001];

long long func(int a) { // 1의 횟수에 대한 답, 0은 이전 것이 답이다. (1이 n번째이면 0은 n-1번 째)
    for (int i = 3; i <= a; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 15746; // 나눈 수를 넣는다.
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