#include <iostream>
#include <string>
using namespace std;
#define MAX 64
int arr[MAX][MAX];

string func(int a, int b, int n) {
    // 탈출조건
    int num = arr[a][b];
    bool divide = false;
    for (int i = a; i < a + n; i++) {
        for (int j = b; j < b + n; j++) {
            if (arr[i][j] != num) { // 처음 숫자와 달라지면 분할
                divide = true; break;
            }
        }
    }
    string ans = "("; // 정답을 넣을 문자열
    if (divide) {
        n = n / 2;
        ans += func(a, b, n); // 왼쪽 위부터 시계뱡향으로 문자열에 값을 추가
        ans += func(a, b + n, n);
        ans += func(a + n, b, n);
        ans += func(a + n, b + n, n);
        ans += ")";
        return ans;
    }
    // 수 세기
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
