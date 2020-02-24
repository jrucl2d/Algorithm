#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000 // ������ ū ��

// ���ͽ�Ʈ�� �˰���(Dijkstra Algorithm) : ������� �˰� �ִ� �ִ� ��θ� ����ؼ� ����
// 1. ��߳�� ����
// 2. ��߳�带 �������� �� ����� �ּ� ��� ����
// 3. �湮���� ���� ��� �߿��� ���� ����� ���� ��� ����
// 4. �ش� ��带 ���ļ� Ư���� ���� ���� ��츦 ����ؼ� �ּ� ��� ����
// �켱���� ť(��)�� �̿��ؼ� O(nlogn)�� �ð����⵵ ���� �ذ� ����
int v, e, k;
vector<pair<int, int>>* arr; // �Ÿ� ��, �ش� ���������� �̾��� ����
priority_queue <pair<int, int>>pq; // {��, ����}���� �̷���� ���� ���� �켱���� ť(��)
int *dist; // �Ÿ��� ������ ����

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> v >> e >> k; // ����, ����, ���� ����

	arr = new vector<pair<int, int>>[v + 1]; // ������ 1���� �����ϹǷ� v+1���� ���� �����Ҵ�

	int from, to, val; // �Է¹��� ���
	for (int i = 0; i < e; i++) {
		cin >> from >> to >> val;
		arr[from].push_back({ val, to }); // �Ÿ� ��, �ش� ���������� �̾��� ���� ������ ���Ϳ� push���ش�.
	}
	dist = new int[v + 1];
	for (int i = 1; i <= v; i++)
		dist[i] = INF; // �ʱ� �Ÿ��� �� ���Ѵ�� ����
	dist[k] = 0; // ���� ������ �Ÿ��� 0�̴�.
	pq.push({ 0, k }); // ���� ������ �־��ش�.

	while (!pq.empty()) {
		int beforeval = -pq.top().first; // ��������� �Ÿ� ��. �켱���� ť�� �ִ� ���̹Ƿ� �ּ� �Ÿ������� ���� ���� - ����
		int beforeloc = pq.top().second; // ������ ��� ��ġ(����)
		pq.pop();
		
		for (int i = 0; i < arr[beforeloc].size(); i++) { // ���� ������ ����� ��� ��忡 ���ؼ�
			int nextval = arr[beforeloc][i].first; // ���� ��忡�� �̾��� i��° ����� �Ÿ� ��
			int nextloc = arr[beforeloc][i].second; // ���� ��忡�� �̾��� i���� ����� ��ġ(����)

			if (dist[nextloc] > dist[beforeloc] + nextval) {
				dist[nextloc] = dist[beforeloc] + nextval;
				pq.push({ -dist[nextloc], nextloc }); // ���� ����� ������ �켱���� ť�� �־���
			}	
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			cout << "INF" << "\n";
		else if (i == k)
			cout << 0 << "\n";
		else
			cout << dist[i]<<"\n";
	}
}