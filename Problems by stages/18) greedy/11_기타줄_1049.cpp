#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<pair<int, int>>strings;
	int n, m; // n�� ���� �� ��, m�� �귣�� ��
	cin >> n >> m;
	int tmp1, tmp2;
	int minSet = 1000; // ��Ʈ �� ���� �� ����
	int minOnly = 1000; // ���� �� ���� �� ����
	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> tmp2;
		minSet = min(minSet, tmp1);
		minOnly = min(minOnly, tmp2);
		strings.push_back(make_pair(tmp1, tmp2));
	}
	if (n < 6) { // n�� 6 �����̸� ��Ʈ �ϳ��� ���� ��
		cout << min(minSet, minOnly * n);
	}
	else { // n�� 6 �̻��̰�
		if (n % 6 == 0) // 6���� ������ �������� ��Ʈ�� ���� �� 
			cout << min(minSet * (n / 6), minOnly * n);
		else { // 6���� �� ������ ��������
			// �ִ��� ��Ű�� �������� �ΰ� ��� �������� ������ ����, ���� ���� ��
			int minNum1 = min(minSet * (n / 6) + minOnly * (n % 6), minOnly * n);
			// ��� ��Ű�� �������� ���� ��
			int minNum2 = minSet * (n / 6 + 1);
			cout << min(minNum1, minNum2);
		}
	}
}