#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// LIS ����
int main() {
	vector<int>link;
	vector<int>lis;
	int num;
	scanf("%d", &num); // ��Ʈ ��
	int tmp;
	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		link.push_back(tmp);
	}
	lis.push_back(link[0]); // ù ��� ����ֱ�
	for (int i = 1; i < num; i++) {
		if (lis.back() < link[i]) {// link�� ���� ���� lis�� ������ ������ ũ��
			lis.push_back(link[i]); // ���� ���� lis�� �߰�
		}
		else { // link�� ���� ���� lis�� ������ ������ ������ ��ü
			auto it = lower_bound(lis.begin(), lis.end(), link[i]);
			*it = link[i];
		}
		/*for (int i = 0; i < lis.size(); i++)
			cout << lis[i] << " ";
		cout << endl;*/
	}
	cout << lis.size(); // lis�� ����� ����
}