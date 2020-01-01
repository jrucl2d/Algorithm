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
        // 마지막 판을 제외한 모든 판을 2번 장대로 옮긴다.
        cal(num - 1, first, third, second);
        // 마지막 판을 3번 장대로 옮긴다.
        cal(1, first, second, third);
        // 2번 장대의 모든 것을 3번 장대로 옮긴다.
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
    printf("%d\n", (int)pow(2, n) - 1); // 두 가지 방법으로 출력 가능
    cal(n, 1, 2, 3);
}