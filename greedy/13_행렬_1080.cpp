#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, m, cnt = 0;
vector<string> a;
vector<string> b;
void flip(int x, int y) {
    cnt++;
    int i, j;
    for (i = 0; i < 3; i++) { // 3 x 3�� ��� ����
        for (j = 0; j < 3; j++) {
            if (a[x + i][y + j] == '0') a[x + i][y + j] = '1';
            else a[x + i][y + j] = '0';
        }
    }
}
int main() {
    int i, j;
    string s;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> s;
        a.push_back(s);
    }
    for (i = 0; i < n; i++) {
        cin >> s;
        b.push_back(s);
    }
    for (i = 0; i < n - 2; i++) { // a�� b�� �ٸ� ��� flip ����
        for (j = 0; j < m - 2; j++) {
            if (a[i][j] != b[i][j]) {
                flip(i, j);
            }
        }
    }
    bool flag = true;
    for (i = 0; i < n; i++) { // ������ a�� b ��
        if (flag) {
            for (j = 0; j < m; j++) {
                if (a[i][j] != b[i][j]) { // �ٸ��� -1 ��� �� ��
                    cout << "-1\n";
                    flag = false;
                    break;
                }
            }
        }
    }
    if (flag) cout << cnt << endl;
}