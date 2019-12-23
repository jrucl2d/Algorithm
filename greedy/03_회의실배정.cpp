#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
/// �ִ��� ���� ������ ����� ó�� <-- ���� ������ ������ ���� �ʿ�
/// ���� ��ġ�� �ʴ� ������ ��� �̾� ����
int main() {
	vector<pair<int, int>>set;
	int conferenceNum;
	cin >> conferenceNum;
	int tmp1, tmp2;
	for (int i = 0; i < conferenceNum; i++) {
		cin >> tmp1 >> tmp2;
		set.push_back(make_pair(tmp2, tmp1)); // tmp2(������ �ð�)�� ����
	}
	sort(set.begin(), set.end());
	int end = set[0].first;
	int count = 1;
	for (int i = 1; i < conferenceNum; i++) {
		if (set[i].second >= end) { // ���� ���� �ּҰ� ������ Ŀ�߸�
			count++;
			end = set[i].first; // end�� ����
		}
	}
	cout << count;
}