#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int ans[26]; // ���ĺ� 26��
	for (int i = 0; i < 26; i++)
		ans[i] = -1;
	for (int i = 0; i < s.size(); i++) {
		if (ans[s[i] - 'a'] == -1) // ó�� ã�� �͸� �ش�ǵ���
			ans[s[i] - 'a'] = i; // �ش� �ε����� ���� ����
	}
	for (int i = 0; i < 26; i++)
		cout << ans[i] << " ";
}