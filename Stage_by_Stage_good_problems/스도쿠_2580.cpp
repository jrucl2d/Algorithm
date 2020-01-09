#include <iostream>
#include <vector>
using namespace std;
#define MAX 9

int sudoku[MAX][MAX];
vector<pair<int, int>> index;

bool rowCheck(int row, int num) { // row 검사
	for (int i = 0; i < MAX; i++)
		if (sudoku[row][i] == num)
			return false;
	return true;
}
bool colCheck(int col, int num) { // col 검사
	for (int i = 0; i < MAX; i++)
		if (sudoku[i][col] == num)
			return false;
	return true;
}
bool nineCheck(int row, int col, int num) { // 9개 검사
	row = row / 3; col = col / 3;
	for (int i = row * 3; i < row * 3 + 3; i++) 
		for (int j = col * 3; j < col * 3 + 3; j++)
			if (sudoku[i][j] == num)
				return false;
	return true;
}
void dfs(int count) { // back tracking 실행
	if (count == index.size()) { // 빈 칸 없을 때까지
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0); // 찾으면 아예 종료
	}
	for (int i = 1; i <= 9; i++) {
		int a = index[count].first; // 빈 칸의 행
		int b = index[count].second; // 빈 칸의 열
		if (rowCheck(a, i) && colCheck(b, i) && nineCheck(a, b, i)) { // 모든 조건 만족시
			sudoku[a][b] = i; // 해당 숫자 넣어줌
			dfs(count + 1);
			sudoku[a][b] = 0; // 다음 검사를 위해 다시 비워줌
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// 입력 받기
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> sudoku[i][j];
			if(sudoku[i][j] == 0)
				index.push_back(make_pair(i, j));
		}
	}
	dfs(0);
}