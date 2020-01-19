#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 100000

int stack[MAX];
int top = -1;
void push(int n) {
	stack[++top] = n;
}
int pop() {
	return stack[top--];
}
bool empty() {
	if (top == -1)
		return true;
	else return false;
}
void clear() {
	top = -1;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> ans;
	while (n-- > 0) {
		string ps;
		cin >> ps;
		bool endGame = false;
		for (int i = 0; i < ps.length(); i++) {
			if (ps[i] == '(')
				push(1);
			else if (ps[i] == ')') {
				if (!empty())
					pop();
				else // 스택이 비었는데 )이 나온다 < 주의!!
					endGame = true;
			}
		}
		if (endGame) {
			ans.push_back("NO");
		}
		else {
			if (empty())
				ans.push_back("YES");
			else ans.push_back("NO");
		}
		clear();
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}