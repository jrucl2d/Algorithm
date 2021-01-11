#include <iostream> // ī����(���)����
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cnt[8001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int tmp;
	int sum = 0;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		cnt[tmp + 4000]++;
		v.push_back(tmp);
	}
	// ��� ���
	double avg = (double)sum / n;
	cout << round(avg) << '\n'; // �ݿø�
	// �߾Ӱ�
	sort(v.begin(), v.end());
	cout << v[v.size() / 2] << '\n';
	// �ֺ�
	int wantIndex = -1;
	int wantMax = 0;
	bool second = false; // �� ��°�� �ľ�
	for (int i = 0; i <= 8000; i++) 
		wantMax = max(wantMax, cnt[i]); // wantMax�� ã�� ����
	for (int i = 0; i <= 8000; i++) { // �� �� �� ��° �� ã��
		if (wantMax == cnt[i]) {
			wantIndex = i;
			if(second)
				break;
			second = true;
		}
	}
	cout << wantIndex - 4000 << '\n';
	// ����
	cout << v.back() - v.front() << '\n';
}