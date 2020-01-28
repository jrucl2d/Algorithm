#include <iostream>
using namespace std;
typedef long long ll;
ll matrix[2][2] = { 1,1,1,0 }; // n+2, n+1은 이 행렬과 n+1, n을 곱했을 때 나온다.
// 따라서 matrix를 n번 곱하고 1,0과 곱하면 n + 1, n이 나온다.
#define mod 1000000
ll tmp[2][2];

void mul(ll a[2][2], ll b[2][2]) { // matrix를 제곱하는 함수
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= mod;
        }
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            a[i][j] = tmp[i][j];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);

    ll n;
    cin >> n;
    ll ans[2][2] = { 1,0,0,1 };
    while (n > 0) {
        if (n % 2 == 1) { // 홀수의 경우
            mul(ans, matrix); // 밑을 한 번 더 곱해주고
        }
        mul(matrix, matrix); // 홀,짝 상관 없이 제곱
        n /= 2; // n을 절반으로
    }
    // ans에 matrix를 n번 제곱한 수가 나왔으므로 밑 두 개와 1, 0을 곱하면 n이 나온다.
    // 따라서 ans의 [1][0]값이 정답이다.
    cout << ans[1][0];
}