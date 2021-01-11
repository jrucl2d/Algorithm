#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100000 + 1

int arr[MAX];
int visited[MAX]; // ������ �ð� ���

int n, k;

void bfs(int a) {
	queue<int>q;
	q.push(a); // ù ���� ť�� �߰�

	while (!q.empty()) {

		a = q.front();
		q.pop(); // �� ���� ��� ����
		if (a == k) // Ż�� ����
			break;

		if (0 <= a - 1 && visited[a - 1] == 0) { // ���� ������ a-1�� ��ġ�� �湮 ���̶��
			visited[a - 1] = visited[a] + 1;
			q.push(a - 1);
		}
		if (a + 1 < MAX && visited[a + 1] == 0) { // ���� ������ a+1�� ��ġ�� �湮 ���̶��
			visited[a + 1] = visited[a] + 1;
			q.push(a + 1);
		}
		if (2 * a < MAX && visited[a * 2] == 0) {
			visited[a * 2] = visited[a] + 1;
			q.push(2 * a);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n >> k;
	visited[n] = 0; // ó������ 0�ʿ��� ����
	bfs(n);
	cout << visited[k];
}