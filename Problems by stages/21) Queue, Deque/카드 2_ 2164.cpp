#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#include <queue>
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	queue<int>q;
	for (int i = 1; i <= n; i++) 
		q.push(i);
	while (q.size() > 1) {
		q.pop(); // 제일 위에 거 버린다.
		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	cout << q.back();
}