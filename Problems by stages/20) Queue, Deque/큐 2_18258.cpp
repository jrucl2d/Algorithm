#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define MAX 2000000
int queue[MAX];
int rear = -1;
int fr = -1;
using namespace std;
void push(int n) {
	queue[++rear] = n;
}

int size() {
	return rear - fr;
}
int empty() {
	if (rear == fr)
		return 1;
	else return 0;
}
int front() {
	if (empty() == 0)
		return queue[fr + 1];
	else return -1;
}
int pop() {
	if (empty() == 0)
		return queue[++fr];
	else return -1;
}
int back() {
	if (empty() == 0)
		return queue[rear];
	else return -1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	int num;
	vector<int>ans;
	while (n-- > 0) {
		cin >> s;
		if (s == "push") {
			cin >> num;
			push(num);
		}
		else if (s == "pop") {
			ans.push_back(pop());
		}
		else if (s == "front") {
			ans.push_back(front());
		}
		else if (s == "back") {
			ans.push_back(back());
		}
		else if (s == "size") {
			ans.push_back(size());
		}
		else if (s == "empty") {
			ans.push_back(empty());
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}