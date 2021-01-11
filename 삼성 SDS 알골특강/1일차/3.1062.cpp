#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
vector<string> words;
vector<bool> visited(26);
int ans = 0;

void getCanWords() {
	int number = 0;

	for (int i = 0; i < n; i++) {
		bool isIt = true;
		for (int j = 0; j < words[i].size(); j++) {
			if (!visited[words[i][j] - 'a']) {
				isIt = false;
				break;
			}
		}
		if (isIt) {
			number += 1;
		}
	}
	ans = max(ans, number);
	return;
}

void dfs(int index, int selNum) {
	if (selNum == k) {
		getCanWords();
		return;
	}
	for (int next = index; next < 26; next++) {
		if (visited[next] == false) {
			visited[next] = true;
			dfs(next, selNum + 1);
			visited[next] = false;
		}
	}
}

int main() {
	cin >> n >> k;
	if (k < 5) {
		cout << 0 << endl;
		return 0;
	}

	// a, n, t, i, c <- default
	visited['a' - 'a'] = true;
	visited['n' - 'a'] = true;
	visited['t' - 'a'] = true;
	visited['i' - 'a'] = true;
	visited['c' - 'a'] = true;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		words.push_back(tmp);
	}

	dfs(0, 5);
	cout << ans << endl;
	return 0;
}