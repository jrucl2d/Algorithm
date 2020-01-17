#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>v;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	// gcd�� �����ؼ� ����
	int result = v[1] - v[0];
	for (int i = 2; i < n; i++) {
		result = gcd(result, v[i] - v[i - 1]);
	}
	vector<int>ans;
	for (int i = 2; i * i <= result; i++) { // �����ٱ����� �غ���
		if (result % i == 0) {
			ans.push_back(i); // �ش� �ε����� ��
			ans.push_back(result / i); // �ٸ� �ϳ��� �ش� ������ ���� ��
		}
	}
	ans.push_back(result); // �ڱ� �ڽŵ� ����
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end()); // �ߺ� ����
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}