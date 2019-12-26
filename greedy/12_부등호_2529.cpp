#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, in1[10], in2[10], MIN[10], MAX[10];
char c;
vector<int> e[10];
string minResult, maxResult;
int main() {
    // n과 부등호를 입력 받음
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == '<') { // i < i+1 이라면
            e[i + 1].push_back(i); // i+1에 연결된 놈 중 하나가 i이다.
            in1[i]++, in2[i]++; // i는 차수가 증가한다.
        }
        else { // i > i+1 이라면
            e[i].push_back(i + 1); // i에 연결된 놈 중 하나가 i+1이다.
            in1[i + 1]++, in2[i + 1]++; // i+1은 차수가 증가한다.
        }
    } // 결과적으로 max가 들어갈 곳이 차수가 적게 된다. 
    //for (int i = 0; i <= n; i++)
    //    cout << in1[i] << " ";
    //cout << endl;
    //for (int i = 0; i <= n; i++)
    //    cout << in2[i] << " ";
    for (int i = 0; i <= n; i++) { // 총 n번 반복
        for (int j = 0; j <= n; j++) {
            if (!in1[j]) {
                MAX[j] = 9 - i, in1[j] = 100; // 다음엔 ln1[j]가 안 걸리도록 수를 바꿔줌
                for (int k = 0; k < e[j].size(); k++) in1[e[j][k]]--; // j랑 연관된 놈들을 다 차수를 감소
                break;
            }
        }
        for (int j = n; j >= 0; j--) { // 같은 그래프를 아래서부터 훑고 오는 것이다.
            if (!in2[j]) { // 그래프의 종속 관계는 같고, 위부터 훑는지 아래부터 훑는지가 다르다.
                MIN[j] = n - i, in2[j] = 1;
                for (int k = 0; k < e[j].size(); k++) in2[e[j][k]]--;
                break;
            }
        }
    }
    for (int i = 0; i <= n; i++) { 
        maxResult += MAX[i] + '0';
        minResult += MIN[i] + '0';
    }
    cout << maxResult << endl << minResult;
}