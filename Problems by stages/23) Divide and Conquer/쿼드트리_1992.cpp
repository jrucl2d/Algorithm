#include <iostream>
#include <string>
using namespace std;
#define MAX 64
int arr[MAX][MAX];

string func(int a, int b, int n) {
    // Ż������
    int num = arr[a][b];
    bool divide = false;
    for (int i = a; i < a + n; i++) {
        for (int j = b; j < b + n; j++) {
            if (arr[i][j] != num) { // ó�� ���ڿ� �޶����� ����
                divide = true; break;
            }
        }
    }
    string ans = "("; // ������ ���� ���ڿ�
    if (divide) {
        n = n / 2;
        ans += func(a, b, n); // ���� ������ �ð蓇������ ���ڿ��� ���� �߰�
        ans += func(a, b + n, n);
        ans += func(a + n, b, n);
        ans += func(a + n, b + n, n);
        ans += ")";
        return ans;
    }
    // �� ����
    if (num == 1)
        return "1";
    else return "0";
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    cout<< func(0, 0, n);
}
