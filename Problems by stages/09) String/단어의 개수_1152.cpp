#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	getline(cin, s);
	vector<string> v;
	stringstream ss(s); // s를 넣은 stringstream ss 생성
	string tmp;
	while (getline(ss, tmp, ' ')) {
		if(isupper(tmp[0]) || islower(tmp[0])) // 공백이 아니면 넣기
			v.push_back(tmp);
	}
	cout << v.size();
}