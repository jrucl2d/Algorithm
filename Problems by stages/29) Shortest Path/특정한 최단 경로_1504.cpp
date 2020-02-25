#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ���ͽ�Ʈ�� �˰��� ���
// �� ���� m1, m2�� ������ ������ �ϹǷ� 1-m1-m2-n�� 1-m2-m1-n �� �� �ϳ��� ��

#define MAX 800 + 1
#define INF 10000000
int n, e;
int m1, m2; // must1, must2. ������ ���ľ� �ϴ� �� ����

vector<pair<int, int>>arr[MAX]; // arr[����]�� �̾��� {���� ���������� �Ÿ�, ���� ����}
int dist[MAX]; // �ش� index �������� ������ �Ÿ��� ������ �迭

int func(int start, int end) {
	for (int i = 0; i <= n; i++) // dist�� ��� ��Ҹ� ���Ѵ�� �ʱ�ȭ
		dist[i] = INF;
	dist[start] = 0; // ó�� �������� ������ �Ÿ��� 0
	priority_queue<pair<int, int>>pq; // {������ �Ÿ�, ����}���� �̷���� �켱���� ť(�ִ� ��)
	pq.push({ 0, start }); // ���� ������ �Ÿ��� 0�̰� ������ �ش� ���� �����̴�.

	while (!pq.empty()) {
		// �켱���� ť�� �ִ� ���ε�, �ּ� �Ÿ��� ���ؾ� �ϹǷ� ���� �ڵ忡�� ť�� ���� �� -�� �ٿ��� �ִ´�.
		// ���� �� ���� -�� �־ ���� �Ѵ�.
		int beforeval = -pq.top().first; // ������ �Ÿ� ��
		int beforeloc = pq.top().second; // ������ ��ġ
		pq.pop(); // ���� ������ ���������Ƿ� ť���� ����.

		for (int i = 0; i < arr[beforeloc].size(); i++) { // ���� loc�� ����� ��� �����鿡 ���ؼ�
			int nextval = arr[beforeloc][i].first; // ���� ���������� �Ÿ�
			int nextloc = arr[beforeloc][i].second; // ���� ����

			// ���� ���� ������ ����(ó���̶� INF����, �� �� ���߾ � ���� ��������)��
			// ���� ���������� ���̿� ���� �������� ���� ���������� �Ÿ��� ���� ������ ������ ġȯ 
			if (dist[nextloc] > dist[beforeloc] + nextval) {
				dist[nextloc] = dist[beforeloc] + nextval;
				pq.push({ -dist[nextloc], nextloc });
			}
		}
	}
	if (dist[end] == INF) // ���� start���� end������ �̾��� ���� ���ٸ� �ʱⰪ INF�� ���
		return -1;
	else return dist[end]; // ���� �����ϸ� �� �ּҰ� ���
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n >> e; 

	int a, b, c; // a�� b�� �̾����ְ�, �Ÿ��� c
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr[a].push_back({ c, b });
		arr[b].push_back({ c, a });
	}
	cin >> m1 >> m2;
	int one1 = func(1, m1); // 1-m1-m2-n�� ���
	int one2 = func(m1, m2);
	int one3 = func(m2, n);
	bool one = true;
	if (one1 == -1 || one2 == -1 || one3 == -1) // ���߿� ���� ������ ǥ��
		one = false;
	int two1 = func(1, m2); // 1-m2-m1-n�� ���
	int two2 = func(m2, m1);
	int two3 = func(m1, n);
	bool two = true;
	if (two1 == -1 || two2 == -1 || two3 == -1) // ���߿� ���� ������ ǥ��
		two = false;
	if (!one && !two) // �ƿ� ���� ������ -1
		cout << -1;
	else if (one && !two) // �� �� ���� �����ϴ� �� ���
		cout << one1 + one2 + one3;
	else if (!one && two)
		cout << two1 + two2 + two3;
	else cout << min(one1 + one2 + one3, two1 + two2 + two3); // �� �� �����ϸ� ���� ª�� �� ���
}