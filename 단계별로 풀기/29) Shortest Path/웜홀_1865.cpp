#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 500 + 1
#define INF 10000000

int tc;
int n, m, w;
vector<pair<int, int>>*arr; // arr[��������] {���� ����, ����ġ}
int *dist; // �Ÿ� ����ġ ���� ����

int func(int cnt) {
	int changed = 0;

	for (int i = 1; i <= n; i++) { // ���� ���� ��ŭ �ݺ�
		for (int j = 1; j <= n; j++) { // j �ε��� ������ ������ ���ؼ�
			for (int k = 0; k < arr[j].size(); k++) { // �� ������ ����� ��� ���鿡 ���ؼ�
				int newval = dist[j] + arr[j][k].second; // ���� ������ ����ġ ���� + �ű� ����� k�� ����ġ(���ο� ��)
				int beforeval = dist[arr[j][k].first]; // �׳� j�� ����� k�� ����� �ִ� ����ġ ������(���� ��)

				if (dist[j] != INF && newval < beforeval) { // j�� INF�̸� ����ġ ���ص� ������ INF�� ���ǹ�. ���� �� ���� �� ������
					changed = 1;
					if (changed * cnt != 0) // ó�� �����̸� cnt�� 0�̹Ƿ� ���� ����. �� ��° �����̸� 1�̶� ���� �� ����Ǹ� ���� ����
						return changed;
					dist[arr[j][k].first] = newval; // ���� �� �ش� ������ ���ο� �� ����
				}
			}
		}
	}
	return changed;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> tc;
	while (tc-- > 0) {

		arr = new vector<pair<int, int>>[MAX];
		dist = new int[MAX];

		cin >> n >> m >> w;
		int s, e, t;
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			arr[s].push_back({ e, t }); // ����� ����
			arr[e].push_back({ s, t });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			arr[s].push_back({ e, -t }); // ��Ȧ�� �ܹ����̰�, t��ŭ �پ��� ������ -����ġ
		}

		for (int i = 2; i <= n; i++) // ����ġ ������ INF�� �ʱ�ȭ
			dist[i] = INF;
		dist[1] = 0; // �������� ����ġ 0

		func(0); // ù �������� �ּ� �� ã��
		if (func(1) != 0) // ������ �����ϸ� 0 �̿��� ���� ���ϵ�
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
		delete[]arr;
		delete[]dist;
	}
}