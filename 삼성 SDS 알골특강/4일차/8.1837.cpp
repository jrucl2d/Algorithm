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
	// ~k까지의 소수 찾기
	for (int i = 2; i < k; i++) {
		if (checked[i] == false) {
			sosu.push_back(i);
			for (int j = i + i; j <= MAX; j += i) {
				checked[j] = true;
			}
		}
	}
	// k보다 작은 소수 중에 p를 나눈 나머지가 0이되면 안 된다. 
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