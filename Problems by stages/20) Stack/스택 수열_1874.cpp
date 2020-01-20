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
	int num = 1; // ���� �־�� �� ��
	bool nope = false;
	for (int i = 0; i < v.size(); i++) {
		if (num < v[i]) { // ���� ���ڰ� ���ϴ� ���� ���ں��� ������
			while (num <= v[i]) { // ���ÿ� �ִ´�.
				st.push(num++);
				ans.push_back('+');
			}
			st.pop(); // ���� ���� ã���� pop �Ѵ�.
			ans.push_back('-');
		}
		else if (num == v[i]) { // �ٷ� ���� ���� ������
			st.push(num++); // ���ÿ� �־��ٰ� pop �Ѵ�.
			ans.push_back('+');
			st.pop();
			ans.push_back('-');
		}
		else if (num > v[i]) { // ���� ���ϴ� ������ ũ�� ���ÿ� �ִٴ� �Ҹ�.
			int tmp = st.top();
			st.pop();
			ans.push_back('-');
			if (v[i] != tmp) { // ���� Ȯ���ߴµ� �ٸ��� ���� ������ �ִٴ� ���̴�.
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