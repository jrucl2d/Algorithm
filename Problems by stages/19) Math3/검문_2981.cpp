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
	// gcd를 누적해서 구함
	int result = v[1] - v[0];
	for (int i = 2; i < n; i++) {
		result = gcd(result, v[i] - v[i - 1]);
	}
	vector<int>ans;
	for (int i = 2; i * i <= result; i++) { // 제곱근까지만 해보고
		if (result % i == 0) {
			ans.push_back(i); // 해당 인덱스의 값
			ans.push_back(result / i); // 다른 하나는 해당 값으로 나눈 것
		}
	}
	ans.push_back(result); // 자기 자신도 포함
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end()); // 중복 삭제
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}