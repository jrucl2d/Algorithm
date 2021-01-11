#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset ���
using namespace std;

int n, w;
vector<pair<int, int>>v;
vector<int>ans;
int dp[1001][1001]; // 1���� ��� i�� ��ġ, 2���� ��� j�� ��ġ�� ���� �� �Ÿ� ���� �ּ�
// ���� m��° ����� ó���ؾ� �� ��
// 1���� ó���ϸ� dp[m][j] = dp[m - 1][j] + m�� �� �� ����� �Ÿ�����
// 2���� ó���ϸ� dp[i][m] = dp[i][m - 1] +  m�� �� �� ����� �Ÿ�����

int func(int first, int second) {
	if (first == w || second == w)
		return 0; // Ż������, ���� �ٴٸ��� ����

	int& tmp = dp[first][second]; // ������ ����
	if (tmp != -1) return tmp; // �ش� ���¿� ���� �����ϸ� �� �� ����(���ʿ� ��� dp�� -1�� �ʱ�ȭ)

	 // ���� ���´� ���� ù ��°�� �� ��° �� ���������� �ذ��� ��� ��ȣ + 1��° �̴�.
	int next = max(first, second) + 1; 
	int d1, d2;

	if (first == 0) // ó�� ���� �ÿ��� ���� ��ǰ� 1�� ������ ó�� ��ġ(1,1)�� ����
		d1 = abs(v[next - 1].first - 1) + abs(v[next - 1].second - 1);
	else // �������ʹ� ���� ��ǰ� 1�� ������ ���� ��ġ(v[first-1])�� ����
		d1 = abs(v[next - 1].first - v[first - 1].first) + abs(v[next - 1].second - v[first - 1].second);

	if (second == 0) 
		d2 = abs(v[next - 1].first - n) + abs(v[next - 1].second - n);
	else 
		d2 = abs(v[next - 1].first - v[second - 1].first) + abs(v[next - 1].second - v[second - 1].second);

	int case1 = func(next, second) + d1; // 1�� ������ ���� ����� �ô� ���
	int case2 = func(first, next) + d2; // 2�� ������ ���� ����� �ô� ���

	tmp = min(case1, case2); // ������ ���� �� ��� �� �ּҰ��� ����

	return tmp;
}

void print2(int first, int second) { // ������ ���, �̹� ���� ���� �״�� ���󰡸� ������ ����
	if (first == w || second == w)
		return; // Ż������, ���� �ٴٸ��� ����


	 // ���� ���´� ���� ù ��°�� �� ��° �� ���������� �ذ��� ��� ��ȣ + 1��° �̴�.
	int next = max(first, second) + 1;
	int d1, d2;

	if (first == 0) // ó�� ���� �ÿ��� ���� ��ǰ� 1�� ������ ó�� ��ġ(1,1)�� ����
		d1 = abs(v[next - 1].first - 1) + abs(v[next - 1].second - 1);
	else // �������ʹ� ���� ��ǰ� 1�� ������ ���� ��ġ(v[first-1])�� ����
		d1 = abs(v[next - 1].first - v[first - 1].first) + abs(v[next - 1].second - v[first - 1].second);

	if (second == 0)
		d2 = abs(v[next - 1].first - n) + abs(v[next - 1].second - n);
	else
		d2 = abs(v[next - 1].first - v[second - 1].first) + abs(v[next - 1].second - v[second - 1].second);

	int case1 = func(next, second) + d1; // 1�� ������ ���� ����� �ô� ���
	int case2 = func(first, next) + d2; // 2�� ������ ���� ����� �ô� ���

	if (case1 < case2) {
		ans.push_back(1);
		print2(next, second);
	}
	else {
		ans.push_back(2);
		print2(first, next);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> n >> w;
	memset(dp, -1, sizeof(dp)); // dp�迭 -1�� �ʱ�ȭ

	int tmp1, tmp2;
	for (int i = 0; i < w; i++) {
		cin >> tmp1 >> tmp2;
		v.push_back({ tmp1,tmp2 });
	}
	cout << func(0, 0) << '\n'; // v�� ó������ Ž��
	print2(0, 0);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}