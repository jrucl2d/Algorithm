#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int>ropes;
	int num;
	cin >> num;
	int tmp;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		ropes.push_back(tmp);
	}
	sort(ropes.begin(),ropes.end()); // �������� ����, ù ��Ұ� �ּ�
	int max = 0;
	for (int i = 0; i < num; i++) {
		if (max < ropes[i] * (num - i)) max = ropes[i] * (num - i); // �ּҺ��� �ϳ��� �ø��� ���� ������ ������ �� �� ū ���� ������ ����
	}
	cout << max;
}