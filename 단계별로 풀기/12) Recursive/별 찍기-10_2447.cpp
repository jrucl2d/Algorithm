#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

char arr[2201][2201];

void cal(int a, int b, int n) {
    if (n == 1) { // ��� ����ϴٰ� �������� 1�� �Ǹ�
        arr[a][b] = '*';
        return; // ������ ����
    }
    int div = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) // ����� ����α� ���� ���θ�...
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
    // ���
    cal(0, 0, n);
    // ���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j];
        cout << "\n";
    }
}