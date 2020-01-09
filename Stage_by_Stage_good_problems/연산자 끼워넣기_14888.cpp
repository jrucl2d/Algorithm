#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n; // �ִ밪 11
vector <int> num;
int caltmp[4]; // +, -, *, /
vector <char> cal; // �����ڸ� ������ ����
vector <char> tmp;
bool visited[10]; // n-1�� max
int maxAns = -1000000000;
int minAns = 1000000000;

void dfs(int count) {
	if (count == cal.size()) { // ���� ����� ���ؼ� �ִ�� �ּ� ����� ���
		int sum = num[0];
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == '+')
				sum += num[i + 1];
			else if (tmp[i] == '-')
				sum -= num[i + 1];
			else if (tmp[i] == '*')
				sum *= num[i + 1];
			else if (tmp[i] == '/')
				sum /= num[i + 1];
		}
		maxAns = max(maxAns, sum);
		minAns = min(minAns, sum);
		return;
	}
	for (int i = 0; i < cal.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			tmp.push_back(cal[i]);
			dfs(count + 1);
			visited[i] = false;
			tmp.pop_back();
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// ���� �Է� �ޱ�, ������ �Է¹ޱ�
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		num.push_back(tmp);
	}
	char calPut[5] = { '+', '-', '*', '/' };
	for (int i = 0; i < 4; i++) {
		cin >> caltmp[i];
		for (int j = 0; j < caltmp[i]; j++) {
			cal.push_back(calPut[i]); // �ش� ������ ����ֱ�
		}
	}
	dfs(0);
	cout << maxAns << "\n" << minAns;
}