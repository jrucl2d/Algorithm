#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
pair<int, int> jew[300001];
int bag[300001];

int main() {
	priority_queue<int> pq; // max heap

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		jew[i] = { a, b };
	}
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		bag[i] = a;
	}

	// 가방 정렬
	sort(bag, bag + k);

	// 보석 무게순 정렬
	sort(jew, jew + n);

	long long  ans = 0;
	int jewIndex = 0;
	for (int i = 0; i < k; i++) {
		while (jewIndex < n && jew[jewIndex].first <= bag[i]) {
			pq.push(jew[jewIndex].second);
			jewIndex++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << endl;
	return 0;
}