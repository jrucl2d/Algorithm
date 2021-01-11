#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 10000

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
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>ans;
	while (n-- > 0) {
		string s;
		int num;
		cin >> s;
		if (s == "push") {
			cin >> num;
			push(num);
		}
		else if (s == "top") {
			if (empty()) ans.push_back(-1);
			else ans.push_back(stack[top]);
		}
		else if (s == "pop") {
			if (empty()) ans.push_back(-1);
			else ans.push_back(pop());
		}
		else if (s == "size") {
			ans.push_back(top + 1);
		}
		else if (s == "empty") {
			if (empty()) ans.push_back(1);
			else ans.push_back(0);
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}