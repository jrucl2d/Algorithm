#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>
using namespace std;
int t, airport, money, ticket;
#define MAX 100 + 1
#define INF 10000000
typedef tuple<int, int, int> tupe;

int dp[MAX][10000 + 1]; // 1�� ��忡�� i�� ������ j�� ������� ���� ���� �ּ� �ð� ����

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> t;
	while (t-- > 0) {
		vector<tupe>arr[MAX]; // ������ ���ͽ�Ʈ�󿡼� vector �ȿ� pair�� ���� ��ó��

		cin >> airport >> money >> ticket;
		int depart, arrive, cost, time;
		for (int i = 0; i < ticket; i++) {
			cin >> depart >> arrive >> cost >> time;
			arr[depart].push_back({ arrive, cost, time });
		}
		// dp �ʱ�ȭ
		for (int i = 1; i <= airport; i++)
			for (int j = 0; j <= money; j++)
				dp[i][j] = INF;
		dp[1][0] = 0; // ù ��° �������� 0�� ������� 0�ð��� �ɸ���.

		priority_queue<tupe, vector<tupe>, greater<tupe>>pq; // {�ð�, ����, ���� ����}, ��������(�ּ� ��)
		pq.push({ 0,0,1 }); // ù ��° �������� ���, �ð��� 0�̴�.

		bool exit = false;
		while (!pq.empty()) {
			int beforeTime = get<0>(pq.top()); // �ð�
			int beforeCost = get<1>(pq.top()); // ����
			int beforeTo = get<2>(pq.top()); // ���� ����
			pq.pop();
			if (beforeTo == airport) { // �־��� cost���� time�� ���� ������ �����Ǿ� �ֱ� ������ �����ϴ� ���� �ٷ� ����ϸ� ��
				cout << beforeTime << "\n";
				exit = true;
				break;
			}
			// �̹� dp�� ����ȴ�� beforeTo ������ ���� �ð��� ���� ����� �ð����� �� ���� ��� ���� �����ϴ�.
			if (dp[beforeTo][beforeCost] < beforeTime)
				continue;

			for (int i = 0; i < arr[beforeTo].size(); i++) { // ���� beforeTo ��忡 ����� ��� ��忡 ���ؼ�
				int nextTime = get<2>(arr[beforeTo][i]);
				int nextCost = get<1>(arr[beforeTo][i]);
				int nextTo = get<0>(arr[beforeTo][i]);

				if (beforeCost + nextCost > money) continue; // ������ �ʰ��ع�����

				// ���� ���� ������ (���� �������� ��� + ���� ��忡�� ���� ��� ���� �� ��� ���)���� ���� �� ��� �ð���(���� ����)
				// ���������� �ð��� ���� �ð��� ���� �ð�(���ο� �ð�)���� ª���� ==> ���� ������ �� ������ �׳� ����
				if (dp[nextTo][beforeCost + nextCost] <= beforeTime + nextTime) continue;

				// ��� ���� ���ǿ� �ش� ������ ������, dp���� ���� ����
				pq.push({beforeTime + nextTime, beforeCost + nextCost, nextTo });
				dp[nextTo][beforeCost + nextCost] = beforeTime + nextTime;
			}
		}
		if (!exit)
			cout << "Poor KCM\n";
	}
}