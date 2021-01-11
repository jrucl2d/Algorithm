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
        i--; // 탈출했을 때 초과한 것이므로
        long long remaining = (y - x) - (i * i); // 남은 것을 최대 속도로 이동
        remaining = (long long)ceil((double)remaining / (double)i);
        cout << i * 2 - 1 + remaining << "\n";
    }
}