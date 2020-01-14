#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 1000

int LCS[MAX][MAX];

int main() { // LCS 구현
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string tmp1, tmp2;
	cin >> tmp1 >> tmp2;
	string a = "0" + tmp1, b = "0" + tmp2; // 문자열 앞에 0을 붙여줌
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			if (i == 0 || j == 0){ // 0행 또는 0열은 모두 0으로 초기화
				LCS[i][j] = 0; continue;
			}
			if (a[i] == b[j]) { // 현재 두 글자가 같다면
				LCS[i][j] = LCS[i - 1][j - 1] + 1; // 왼쪽 위에서 1 더함
			}
			else { // 두 글자가 다르다면
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]); // 왼쪽과 위쪽 중에 큰 것으로
			}
		}
	}
	cout << LCS[a.size() - 1][b.size() - 1]; // 마지막 최종 결과물 출력
}