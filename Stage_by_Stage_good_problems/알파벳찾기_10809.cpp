#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int ans[26]; // 알파벳 26개
	for (int i = 0; i < 26; i++)
		ans[i] = -1;
	for (int i = 0; i < s.size(); i++) {
		if (ans[s[i] - 'a'] == -1) // 처음 찾은 것만 해당되도록
			ans[s[i] - 'a'] = i; // 해당 인덱스의 값을 변경
	}
	for (int i = 0; i < 26; i++)
		cout << ans[i] << " ";
}