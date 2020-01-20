#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include <stack>

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int>v;
	int tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	stack<int>st;
	vector<char>ans;
	int num = 1; // 현재 넣어야 할 수
	bool nope = false;
	for (int i = 0; i < v.size(); i++) {
		if (num < v[i]) { // 현재 숫자가 원하는 수열 숫자보다 작으면
			while (num <= v[i]) { // 스택에 넣는다.
				st.push(num++);
				ans.push_back('+');
			}
			st.pop(); // 같은 수를 찾으면 pop 한다.
			ans.push_back('-');
		}
		else if (num == v[i]) { // 바로 같은 수를 만나면
			st.push(num++); // 스택에 넣었다가 pop 한다.
			ans.push_back('+');
			st.pop();
			ans.push_back('-');
		}
		else if (num > v[i]) { // 만약 원하는 수보다 크면 스택에 있다는 소리.
			int tmp = st.top();
			st.pop();
			ans.push_back('-');
			if (v[i] != tmp) { // 빼서 확인했는데 다르면 뭔가 문제가 있다는 뜻이다.
				nope = true;
			}
		}
	}
	if (nope)
		cout << "NO";
	else 
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
}