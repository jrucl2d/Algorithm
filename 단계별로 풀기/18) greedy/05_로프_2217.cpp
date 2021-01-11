#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int>ropes;
	int num;
	cin >> num;
	int tmp;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		ropes.push_back(tmp);
	}
	sort(ropes.begin(),ropes.end()); // 오름차순 정렬, 첫 요소가 최소
	int max = 0;
	for (int i = 0; i < num; i++) {
		if (max < ropes[i] * (num - i)) max = ropes[i] * (num - i); // 최소부터 하나씩 올리며 남은 개수를 곱했을 때 더 큰 무게 가능할 수도
	}
	cout << max;
}
