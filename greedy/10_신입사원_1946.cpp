#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int>answer;
	vector<pair<int, int>>test;
	int testNum;
	cin >> testNum;
	int num;
	int tmp1, tmp2; // ������ �Է� ����
	int count;
	for (int n = 0; n < testNum; n++) {
		test.clear(); // ���� �ʱ�ȭ
		cin >> num; // ��� ��
		for (int i = 0; i < num; i++) { // ���� �Է�
			cin >> tmp1 >> tmp2;
			test.push_back(make_pair(tmp1, tmp2));
		}
		sort(test.begin(), test.end()); // ù ��° ������ �������� ����
		count = 1; // 1���� ������ �հ�
		int tmp = test[0].second;
		for (int i = 1; i < num; i++) { // first ������ ������
			if (test[i].second < tmp) {// second ������ �̱�� �հ�
				count++;
				tmp = test[i].second;
			}
		}
		answer.push_back(count); // ��� push
	}
	for (int i = 0; i < testNum; i++)
		cout << answer[i] << endl;
}