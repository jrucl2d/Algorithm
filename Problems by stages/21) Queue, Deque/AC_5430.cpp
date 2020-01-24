#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    int t;
    cin >> t;
    string s;
    int n;
    while(t-- > 0) {
        cin >> s;
        cin >> n;
        string tmp;
        cin >> tmp;
        bool done = false;
        // 예외조건
        if (tmp == "[]") { // 비었는데
            for(int i = 0 ; i < s.length(); i++)
                if (s[i] == 'D') {
                    done = true; break;
                }
            if (done) // D가 있으면 오류
                cout << "error" << '\n';
            else // 아니면 빈것 출력
                cout << "[]" << '\n';
            continue;
        }   
        string num = "";
        // 덱 dq에 배열 입력 받기
        deque<int>dq;
        for (int i = 1; i < tmp.length(); i++) {
            if (tmp[i] == ',' || tmp[i] == ']') {
                dq.push_back(stoi(num)); // 수로 바꿔서 배열에 넣기
                num = ""; // 초기화
            }
            else 
                num += tmp[i];
        }
        bool stop = false;
        bool left = true;
        // 함수 실행
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') { // 순서 바꾸기
                if (left)
                    left = false;
                else
                    left = true;
            }
            else if (s[i] == 'D') { // front 제거하기
                if (dq.empty()) { // 에러 조건
                    stop = true;
                    break;
                }
                if (left)
                    dq.pop_front();
                else dq.pop_back();
            }
        }
        if (stop) 
            cout << "error" << '\n';
        else {
            cout << '[';

            for (int i = 0; i < dq.size(); i++) {
                if (left)
                    cout << dq[i];
                else
                    cout << dq[dq.size() - 1 - i];
                if (i != dq.size() - 1)
                    cout << ",";
            }
            cout << ']' << '\n';
        }
    }
}
