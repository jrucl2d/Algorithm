#include <iostream>
using namespace std;
typedef long long ll;
#define arrMAX 5 + 1
ll arr[arrMAX][arrMAX];
ll ans[arrMAX][arrMAX];
ll n, b;
ll tmp[arrMAX][arrMAX];

void cal(ll a[arrMAX][arrMAX], ll b[arrMAX][arrMAX]) {
    for (int i = 0; i < n; i++) { // 행렬의 곱 (1000으로 나눈 나머지로)
        for (int j = 0; j < n; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= 1000;
        }
    }
    for (int i = 0; i < n; i++) // 곱셈 결과로 치환
        for (int j = 0; j < n; j++)
            a[i][j] = tmp[i][j];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);

    cin >> n >> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    //  1의 역할을 하는 행렬 생성(결과)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                ans[i][j] = 1;
            else
                ans[i][j] = 0;
        }
    }
    // 분할 정복 방식으로 거듭제곱 구현
    while (b > 0) {
        if (b % 2 == 1) { // 홀수의 경우
             // 결과에 밑을 한 번 곱해준다.
            cal(ans, arr);
        }
        // 짝수, 홀수에 상관 없이 밑을 제곱
        cal(arr, arr);
        b /= 2; // 지수를 반으로 만든다.
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}