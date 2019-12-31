#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool isSosu(int a) {
    int divide = sqrt(a);
    for (int j = 2; j <= divide; j++) { // 1�� �ڱ� �ڽ��� ����
        // ���⼭ ����������� �Ҽ��� �ƴϴ�.
        if (a % j == 0) {
            return false;
        }
    }    
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        int num;
        cin >> num;
        int a = num / 2;
        int b = num - a;
        while (true) {
            if (isSosu(a) && isSosu(b)) break;
            a--; b++;
        }
        cout << a << " " << b << "\n";
    }
}