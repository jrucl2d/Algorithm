#include <iostream>

using namespace std;
#define MAX 8
int arr[MAX];
bool visited[MAX];

int n, m;
void dfs(int start, int count) { // �����ϴ� �ε����� �ʿ�!
	if (count == m) { // Ż�� ����
		for (int i = 0; i < m; i++) 
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = start; i < n; i++) { // �����ϴ� ����(start ���� ����, �̹� ���� ���� ���ϱ�)
		if (!visited[i]) { // �湮 �� �ߴ� ���ڿ� ���ؼ�
			visited[i] = true; // �湮 �� ������ ó��
			arr[count] = i + 1; // count�� index ������ �ϹǷ� �ش� index�� i+1 ���� ����
			dfs(i, count + 1); // ���� �ε����� ���ؼ� �ϵ��� ���(start�� 1�� �����ϹǷ� ���� ���� ���� ����)
			visited[i] = false; // �����̹Ƿ� �ٽ� false��
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	dfs(0, 0);
}