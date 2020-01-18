#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n; // 최대값 11
vector <int> num;
int caltmp[4]; // +, -, *, /
vector <char> cal; // 연산자를 저장할 벡터
vector <char> tmp;
bool visited[10]; // n-1이 max
int maxAns = -1000000000;
int minAns = 1000000000;

void dfs(int count) {
	if (count == cal.size()) { // 최종 결과에 대해서 최대와 최소 결과를 계산
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

	// 숫자 입력 받기, 연산자 입력받기
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
			cal.push_back(calPut[i]); // 해당 연산자 집어넣기
		}
	}
	dfs(0);
	cout << maxAns << "\n" << minAns;
}