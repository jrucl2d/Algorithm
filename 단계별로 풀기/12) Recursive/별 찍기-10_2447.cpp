#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

char arr[2201][2201];

void cal(int a, int b, int n) {
    if (n == 1) { // 계속 계산하다가 마지막에 1이 되면
        arr[a][b] = '*';
        return; // 끝내기 조건
    }
    int div = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) // 가운데를 비워두기 위한 몸부림...
                continue;
            else
                cal(a + (i * div), b + (j * div), div);
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = ' ';
    // 계산
    cal(0, 0, n);
    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j];
        cout << "\n";
    }
}