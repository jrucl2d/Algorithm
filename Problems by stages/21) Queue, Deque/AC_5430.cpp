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
        // ��������
        if (tmp == "[]") { // ����µ�
            for(int i = 0 ; i < s.length(); i++)
                if (s[i] == 'D') {
                    done = true; break;
                }
            if (done) // D�� ������ ����
                cout << "error" << '\n';
            else // �ƴϸ� ��� ���
                cout << "[]" << '\n';
            continue;
        }   
        string num = "";
        // �� dq�� �迭 �Է� �ޱ�
        deque<int>dq;
        for (int i = 1; i < tmp.length(); i++) {
            if (tmp[i] == ',' || tmp[i] == ']') {
                dq.push_back(stoi(num)); // ���� �ٲ㼭 �迭�� �ֱ�
                num = ""; // �ʱ�ȭ
            }
            else 
                num += tmp[i];
        }
        bool stop = false;
        bool left = true;
        // �Լ� ����
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') { // ���� �ٲٱ�
                if (left)
                    left = false;
                else
                    left = true;
            }
            else if (s[i] == 'D') { // front �����ϱ�
                if (dq.empty()) { // ���� ����
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
