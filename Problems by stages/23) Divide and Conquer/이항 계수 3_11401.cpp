#include <iostream>
#include <cmath>
using namespace std;
#define MAX 4000000 + 1
#define mod 1000000007
long long dp[MAX];
// 페르마의 소정리 : p가 소수이고, a가 p의 배수가 아니면 a^(p-1)%p = 1이다.
// nCk = n! * ((k!) * (n-k)!)^-1. 모든 변에 mod를 나누어줄 수 있다. 
// (k! * (n-k)!)^(mod-1) % mod = 1이므로 곱해준다.
// 그럼 (n! % mod * (k! * (n-k)!)^mod-2 % mod) % mod를 구하면 된다.
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    int n, k;
    cin >> n >> k;
    // factorial 구하기
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] * i) % mod;
    long long b = (dp[k] * dp[n - k]) % mod;
    // b의 mod - 2승 구하기 (분할 정복 사용)
    // 홀수일 때는 C^n = C^(n-1)/2 * C^(n-1)/2 * C이고 (하나를 빼서 반 나누고 밑 한 번 더 곱함
    // 짝수일 때는 C^n = C^(n/2) * (n/2) 이다.
    long long index = mod - 2;
    long long ans = 1;
    while (index > 0) {
        if (index % 2 == 1) {
            ans *= b;
            ans %= mod;
        }
        b *= b;
        b %= mod;
        index /= 2;
    }
    cout << ((dp[n] % mod) * (ans % mod)) % mod;
}