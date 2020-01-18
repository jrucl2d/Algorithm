#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 1000

int LCS[MAX][MAX];

int main() { // LCS ����
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string tmp1, tmp2;
	cin >> tmp1 >> tmp2;
	string a = "0" + tmp1, b = "0" + tmp2; // ���ڿ� �տ� 0�� �ٿ���
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			if (i == 0 || j == 0){ // 0�� �Ǵ� 0���� ��� 0���� �ʱ�ȭ
				LCS[i][j] = 0; continue;
			}
			if (a[i] == b[j]) { // ���� �� ���ڰ� ���ٸ�
				LCS[i][j] = LCS[i - 1][j - 1] + 1; // ���� ������ 1 ����
			}
			else { // �� ���ڰ� �ٸ��ٸ�
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]); // ���ʰ� ���� �߿� ū ������
			}
		}
	}
	cout << LCS[a.size() - 1][b.size() - 1]; // ������ ���� ����� ���
}