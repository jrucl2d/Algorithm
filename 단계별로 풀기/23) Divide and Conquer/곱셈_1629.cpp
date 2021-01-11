#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    // 홀수일 때는 C^n = C^(n-1)/2 * C^(n-1)/2 * C이고 (하나를 빼서 반 나누고 밑 한 번 더 곱함
    // 짝수일 때는 C^n = C^(n/2) * (n/2) 이다.
    ll ans = 1;
    ll index = b;
    while (index > 0) {
        if (index % 2 == 1) { // 홀수일 때
            ans *= a; // 결과에 밑을 한 번 곱해준다.
            ans %= c;
        }
        a %= c;
        a *= a; // 짝수/홀수 상관 없이 밑을 제곱한다.
        a %= c;
        index /= 2; // 지수를 반으로 쪼갠다.
    }
    cout << ans % c;
}