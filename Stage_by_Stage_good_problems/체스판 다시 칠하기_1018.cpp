#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
string chess[50];

int count(int a, int b) {
	int Bcount = 0, Wcount = 0;
	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			// BW 체크
			if (i % 2 == 0 && j % 2 == 0 && chess[i][j] == 'B' || i % 2 == 0 && j % 2 == 1 && chess[i][j] == 'W')
				Bcount++;
			else if (i % 2 == 1 && j % 2 == 0 && chess[i][j] == 'W' || i % 2 == 1 && j % 2 == 1 && chess[i][j] == 'B')
				Bcount++;
			// WB 체크
			if (i%2 == 0 && j%2 == 0 && chess[i][j] == 'W' || i % 2 == 0 && j % 2 == 1 && chess[i][j] == 'B')
				Wcount++;
			else if (i % 2 == 1 && j % 2 == 0 && chess[i][j] == 'B' || i % 2 == 1 && j % 2 == 1 && chess[i][j] == 'W')
				Wcount++;
		}
	}
	return 64 - max(Bcount,Wcount); // 8 * 8
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) 
		cin >> chess[i]; // string을 입력받음
	int ans = 10000;
	for (int i = 0; i < a - 7; i++) { // a-8+1
		for (int j = 0; j < b - 7; j++) { // b-8+1
			ans = min(ans, count(i, j));
		}
	}
	cout << ans;
}