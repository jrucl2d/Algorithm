#include <iostream>
#include <vector>
using namespace std;
#define MAX 9

int sudoku[MAX][MAX];
vector<pair<int, int>> index;

bool rowCheck(int row, int num) { // row �˻�
	for (int i = 0; i < MAX; i++)
		if (sudoku[row][i] == num)
			return false;
	return true;
}
bool colCheck(int col, int num) { // col �˻�
	for (int i = 0; i < MAX; i++)
		if (sudoku[i][col] == num)
			return false;
	return true;
}
bool nineCheck(int row, int col, int num) { // 9�� �˻�
	row = row / 3; col = col / 3;
	for (int i = row * 3; i < row * 3 + 3; i++) 
		for (int j = col * 3; j < col * 3 + 3; j++)
			if (sudoku[i][j] == num)
				return false;
	return true;
}
void dfs(int count) { // back tracking ����
	if (count == index.size()) { // �� ĭ ���� ������
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0); // ã���� �ƿ� ����
	}
	for (int i = 1; i <= 9; i++) {
		int a = index[count].first; // �� ĭ�� ��
		int b = index[count].second; // �� ĭ�� ��
		if (rowCheck(a, i) && colCheck(b, i) && nineCheck(a, b, i)) { // ��� ���� ������
			sudoku[a][b] = i; // �ش� ���� �־���
			dfs(count + 1);
			sudoku[a][b] = 0; // ���� �˻縦 ���� �ٽ� �����
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// �Է� �ޱ�
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> sudoku[i][j];
			if(sudoku[i][j] == 0)
				index.push_back(make_pair(i, j));
		}
	}
	dfs(0);
}