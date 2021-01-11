#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    for (int t = 0; t < num; t++)
    {
        int x, y;
        cin >> x >> y;
        long long i = 1;
        while (i * i <= (y - x))
            i++;
        i--; // Ż������ �� �ʰ��� ���̹Ƿ�
        long long remaining = (y - x) - (i * i); // ���� ���� �ִ� �ӵ��� �̵�
        remaining = (long long)ceil((double)remaining / (double)i);
        cout << i * 2 - 1 + remaining << "\n";
    }
}