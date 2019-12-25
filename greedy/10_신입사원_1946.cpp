#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int>answer;
	vector<pair<int, int>>test;
	int testNum;
	cin >> testNum;
	int num;
	int tmp1, tmp2; // 점수를 입력 받음
	int count;
	for (int n = 0; n < testNum; n++) {
		test.clear(); // 벡터 초기화
		cin >> num; // 사람 수
		for (int i = 0; i < num; i++) { // 점수 입력
			cin >> tmp1 >> tmp2;
			test.push_back(make_pair(tmp1, tmp2));
		}
		sort(test.begin(), test.end()); // 첫 번째 점수로 오름차순 정렬
		count = 1; // 1번은 무조건 합격
		int tmp = test[0].second;
		for (int i = 1; i < num; i++) { // first 순위는 졌지만
			if (test[i].second < tmp) {// second 순위가 이기면 합격
				count++;
				tmp = test[i].second;
			}
		}
		answer.push_back(count); // 결과 push
	}
	for (int i = 0; i < testNum; i++)
		cout << answer[i] << endl;
}