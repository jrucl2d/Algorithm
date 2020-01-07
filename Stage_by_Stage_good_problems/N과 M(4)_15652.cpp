#include <iostream>

using namespace std;
#define MAX 8
int arr[MAX];
//bool visited[MAX];

int n, m;
void dfs(int start, int count) { // start �Ű����� �߰�
	if (count == m) { // Ż�� ����
		for (int i = 0; i < m; i++) 
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = start; i < n; i++) { // �����ϴ� ����
		//if (!visited[i]) {				// <- �� ������ ���ּ� ���� ���� ����� �� �ֵ���
			//visited[i] = true;			// <- �� ���ǵ� ���ʿ�
			arr[count] = i + 1; // count�� index ������ �ϹǷ� �ش� index�� i+1 ���� ����
			dfs(i, count + 1); // ���� �ε����� ���ؼ� �ϵ��� ���
			//visited[i] = false;			// <- �� ���ǵ� ���ʿ�
		//}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	dfs(0, 0);
}