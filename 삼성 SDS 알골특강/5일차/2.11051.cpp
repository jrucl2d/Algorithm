#include <iostream>
#define MAX 1001
using namespace std;
int D[MAX][MAX];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				D[i][j] = 1;
				continue;
			}
			else if (i == j) {
				D[i][j] = 1;
				continue;
			}
			else {
				D[i][j] = (D[i - 1][j - 1] + D[i - 1][j]) % 10007;
			}
		}
	}
	cout << D[n][k];
	return 0;
}