#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 50000 + 1
#define INF 10000000

// ���ͽ�Ʈ�� ���
// ���� start-must1-must2-end�� start-must2-must1-end �� �ϳ��� start-end�� ���ٸ� end �ĺ����� �������� �� �� �ִ�. 
// �׷��� �� ����� �� �ĺ����� ���ؼ� ���ͽ�Ʈ�� �� �� ����Ѵ�. 
// ���� Ǯ�� : ��� ���� ����ġ(�Ÿ� ��)�� �� ��� ���ְ�, must1-must2�� ���� -1 ���ش�. 
// �׷��� �ĺ������� ���ͽ�Ʈ�� ����� �߿��� Ȧ���� ���� ���� must1-must2�� ���� �ĺ���� �� �� �����Ƿ� ���ͽ�Ʈ�� �� �� ����Ѵ�.

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	int t; // �׽�Ʈ ���̽� ��
	cin >> t;

	while (t-- > 0) {
		
		int inter, road, goal; // ���� ������, ������, �ĺ�
		int start, must1, must2; // ���� �����, �ݵ�� ������ �ϴ� �ĺ� �� �� 

		vector<int>ans; // ���� ����
		vector<pair<int, int>> arr[MAX]; // arr[��������]���� {���� ���������� �Ÿ�, ��������}
		int dist[MAX]; // �ش� �ε��� �������� ������ �Ÿ� ��
		vector<int>possible; // ���� �ĺ���

		cin >> inter >> road >> goal;
		cin >> start >> must1 >> must2;
		int a, b, d;
		for (int i = 0; i < road; i++) {
			cin >> a >> b >> d;
			d *= 2; // ��� �Ÿ� ����ġ�� �� �� �Ѵ�.
			if ((a == must1 && b == must2) || (a == must2 && b == must1)) // must1-must2�� ����ġ�� �߰��� -1 ���ش�.
				d -= 1;
			arr[a].push_back({ d,b }); // ����� �����̹Ƿ�
			arr[b].push_back({ d,a });
		}
		int x;
		for (int i = 0; i < goal; i++) {
			cin >> x;
			possible.push_back(x); // �ĺ��� ����
		}
		// ���⼭���� ���ͽ�Ʈ�� �˰���
		for (int j = 0; j < goal; j++) { // ��� �ĺ����鿡 ���ؼ�
			priority_queue<pair<int, int>>pq; // {�Ÿ���, ����}

			for (int i = 0; i <= inter; i++) // ��� �Ÿ��� INF�� �ʱ�ȭ
				dist[i] = INF;
			dist[start] = 0; // ��� ���������� �Ÿ��� 0
			pq.push({ 0, start }); // ����� ť�� ����

			while (!pq.empty()) {
				// �ּ� �Ÿ��� ���ؾ� �ϹǷ� ���� �� -�� �ְ� �� ���� -�� ����.
				int beforeval = -pq.top().first; // ���� ������ �Ÿ� ����ġ
				int beforeloc = pq.top().second; // ���� ����
				pq.pop();

				for (int i = 0; i < arr[beforeloc].size(); i++) { // ���� ������ ����� ��� ������ ���ؼ�
					int nextval = arr[beforeloc][i].first;
					int nextloc = arr[beforeloc][i].second;

					if (dist[nextloc] > dist[beforeloc] + nextval) {
						dist[nextloc] = dist[beforeloc] + nextval;
						pq.push({ -dist[nextloc], nextloc }); // ���� �� -�� ����
					}
				}
			}
			if (dist[possible[j]] % 2 == 1 && dist[possible[j]] != INF) // ����� ���� Ȧ���̸� �信 ����
				ans.push_back(possible[j]);
			sort(ans.begin(), ans.end()); // �������� ����
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
}