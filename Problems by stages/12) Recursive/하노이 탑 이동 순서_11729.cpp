#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void cal(int num, int first, int second, int third) { // from, not using, to
    if (num == 1) {
        printf("%d %d\n", first, third);
    }
    else {
        // ������ ���� ������ ��� ���� 2�� ���� �ű��.
        cal(num - 1, first, third, second);
        // ������ ���� 3�� ���� �ű��.
        cal(1, first, second, third);
        // 2�� ����� ��� ���� 3�� ���� �ű��.
        cal(num - 1, second, first, third);
    }
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    /*int cnt = 1;
    for (int i = 1; i < n; i++) {
        cnt *= 2;
        cnt++;
    }
    cout << cnt << '\n';*/
    printf("%d\n", (int)pow(2, n) - 1); // �� ���� ������� ��� ����
    cal(n, 1, 2, 3);
}