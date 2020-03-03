#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool yes[21]; // 1~20의 숫자가 존재하는지 파악

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	int m;
	cin >> m;
	string st;
	int x;
	while (m-- > 0) {
		cin >> st;
		if (st == "add") {
			cin >> x;
			if (!yes[x]) // 없다면 추가
				yes[x] = true;
		}
		else if (st == "remove") {
			cin >> x;
			if (yes[x]) 
				yes[x] = false;
		}
		else if (st == "check") {
			cin >> x;
			if (yes[x])
				cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (st == "toggle") {
			cin >> x;
			if (!yes[x])
				yes[x] = true;
			else if(yes[x]) 
				yes[x] = false;
		}
		else if (st == "all") 
			for (int i = 1; i <= 20; i++)
				yes[i] = true;
		else if (st == "empty") 
			for (int i = 1; i <= 20; i++)
				yes[i] = false;
	}
}