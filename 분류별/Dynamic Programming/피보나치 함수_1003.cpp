#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxN = 0;
int arr[41];

void fibonacci(int a) { // 1의 횟수에 대한 답, 0은 이전 것이 답이다. (1이 n번째이면 0은 n-1번 째)
    for (int i = 2; i <= a; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
    arr[0] = 0; arr[1] = 1;

	int t;
    int n;
    vector <int> v;
    cin >> t;
	for (int i = 0; i < t; i++) {
        cin >> n;
        v.push_back(n);
        maxN = max(n, maxN);
	}
    fibonacci(maxN);
    for (int i = 0; i < t; i++) {
        if (v[i] == 0)
            cout << 1 << " " << 0 << '\n';
        else if (v[i] == 1)
            cout << 0 << " " << 1 << '\n';
        else
            cout << arr[v[i] - 1] << " " << arr[v[i]] << '\n';
    }
}