#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    int n, m;
    cin >> n >> m;
    deque<int>dq;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);
    vector<int>v;
    int tmp;
    int count = 0;
    while (m-- > 0) {
        cin >> tmp;
        while (true) {
            if (dq.front() == tmp) {
                dq.pop_front(); break;
            }
            // tmp�� ����ִ��� ã�´�.
            int i;
            for (i = 0; i < dq.size(); i++)
                if (dq[i] == tmp)
                    break;
            if (i > dq.size() / 2) { // �����ʿ� �ִٸ�
                while (dq.front() != tmp) {
                    dq.push_front(dq.back());
                    dq.pop_back();
                    count++;
                }
            }
            else { // ���ʿ� �ִٸ�
                while (dq.front() != tmp) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    count++;
                }
            }
        }
    }
    cout << count;
}
