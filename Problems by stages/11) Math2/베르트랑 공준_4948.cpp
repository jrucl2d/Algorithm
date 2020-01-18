#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    while (true) {
        cin >> a;
        if (a == 0) break;
        int count = 0;
        for (int i = a + 1; i <= 2 * a; i++) {
            int divide = sqrt(i);
            bool sosu = true;
            for (int j = 2; j <= divide; j++) { // 1과 자기 자신은 제외
                // 여기서 나누어떨어지면 소수가 아니다.
                if (i % j == 0) {
                    sosu = false; break;
                }
            }
            if (sosu) count++;
        }
        cout << count << "\n";
    }
}