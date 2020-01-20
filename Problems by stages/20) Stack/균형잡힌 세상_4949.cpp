#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include <stack>

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	vector<string>ans;
	while (true) {
		getline(cin, s);
		if (s[0] == '.' && s.length() == 1)
			break;
		stack<char>st;
		bool nope = false;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(')
				st.push('(');
			else if (s[i] == '[')
				st.push('[');
			else if (s[i] == ')') {
				// 닫는 괄호 나왔는데 스택 비어있거나 대괄호와 소괄호가 짝지어지면
				if (st.empty() || st.top() == '[') {
					nope = true; // NO
					break;
				}
				else {
					st.pop();
				}
			}
			else if (s[i] == ']') {
				if (st.empty() || st.top() == '(') {
					nope = true; // NO
					break;
				}
				else {
					st.pop();
				}
			}
		}
		if (!nope && st.empty())
			ans.push_back("yes");
		else ans.push_back("no");
		nope = false;
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}