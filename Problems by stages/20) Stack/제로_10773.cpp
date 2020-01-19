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
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n-- > 0) {
		int num;
		cin >> num;
		if (num == 0)
			pop();
		else
			push(num);
	}
	int sum = 0;
	for (int i = 0; i <= top; i++)
		sum += stack[i];
	cout << sum;
}