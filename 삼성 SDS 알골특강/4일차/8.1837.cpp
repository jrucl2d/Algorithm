#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 1000000
bool checked[MAX + 1];
string p;
int k;
vector<int> sosu;

int main() {
	cin >> p >> k;
	// ~k������ �Ҽ� ã��
	for (int i = 2; i < k; i++) {
		if (checked[i] == false) {
			sosu.push_back(i);
			for (int j = i + i; j <= MAX; j += i) {
				checked[j] = true;
			}
		}
	}
	// k���� ���� �Ҽ� �߿� p�� ���� �������� 0�̵Ǹ� �� �ȴ�. 
	for (int so = 0; so < sosu.size(); so++) {
		int nowArr[2] = { 0, p[0] - '0' };
		for (int i = 0; i < p.size(); i++) {
			int now = nowArr[0] * 10 + nowArr[1];
			int r = now % sosu[so];		
			if (i == p.size() - 1) {
				if (r == 0) {
					cout << "BAD " << sosu[so];
					return 0;
  				}
			}
			nowArr[0] = r, nowArr[1] = p[i + 1] - '0';
		}
	}
	cout << "GOOD";

	return 0;
}