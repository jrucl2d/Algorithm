#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string>v;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	vector<int>ans;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		count = 0;
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 'O') {
				count++;
			}
			else if (v[i][j] == 'X') {
				count = 0;
			}
			sum += count;
		}
		ans.push_back(sum);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';
}