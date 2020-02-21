#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 25 + 1

int n;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int cnt = 0;
vector<int>ans;

void dfs(int a, int b) {
	if (arr[a][b] == 0) // �ش� �ڸ��� 0�̸� �׳� ����
		return;
	visited[a][b] = true; // �ش� �ڸ� �Դ� ������ ǥ��
	cnt++; // �� ī��Ʈ
	// ��
	if (visited[a - 1][b] != true && arr[a - 1][b] == 1) {
		dfs(a - 1, b); // ������ dfs�� ����
		arr[a - 1][b] = 0; // �̹� ������ �ڸ��� 0���� ��������
	}
	// ��
	if (visited[a + 1][b] != true && arr[a + 1][b] == 1) {
		dfs(a + 1, b);
		arr[a + 1][b] = 0;
	}
	// ��
	if (visited[a][b - 1] != true && arr[a][b - 1] == 1) {
		dfs(a, b - 1);
		arr[a][b - 1] = 0;
	}
	// ��
	if (visited[a][b + 1] != true && arr[a][b + 1] == 1) {
		dfs(a, b + 1);
		arr[a][b + 1] = 0;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= n; j++)
			arr[i][j] = s[j - 1] - '0';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt = 0; // �Ź� cnt�� 0���� �ʱ�ȭ
			dfs(i, j); // ��� ��쿡 ���ؼ� dfs ����
			if (cnt != 0)
				ans.push_back(cnt);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}