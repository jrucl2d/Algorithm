#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;
// 어차피 더해주는 것은 b랑 같게 더해줄 거니깐
// a와 b의 차이 자체가 전체 차이와 같다.
int main() {
	string a, b;
	cin >> a >> b;
	int resultMin = 50;
	int count = 0;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		for (int j = i; j < i + a.length(); j++) {
			if (a[j-i] != b[j]) count++;
		}
		resultMin = min(count, resultMin);
		count = 0;
	}
	cout << resultMin;
}