#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int count = 1; // Ã³À½¿¡ 1
	int sum = 1;
	while (true) {
		if (sum >= n)
			break;
		sum += 6 * count;
		count++;
	}
	cout << count;
}