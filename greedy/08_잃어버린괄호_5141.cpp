#include <iostream> 
#include <string>
using namespace std;
// 처음엔 식 더해주다가 처음 '-' 만난 다음부터 다 빼주기
int main() {
	string sik;
	cin >> sik;
	bool minus = false;
	int sum = 0;
	string tmp;
	for (int i = 0; i <= sik.length(); i++) { // length는 길이를 return하므로 끝의 NULL을 파악하기 위해
		if (sik[i] == '+' || sik[i] == '-' || sik[i] == '\0') { // 연산자 만나거나 끝이면
			if (minus) {
				sum -= stoi(tmp);
			}
			else {
				sum += stoi(tmp);
			}
			tmp = ""; // tmp 초기화
			if (sik[i] == '-')
				minus = true;
			continue; // 건너뛰기
		}	
		else
			tmp += sik[i];
	}
	cout << sum;
}