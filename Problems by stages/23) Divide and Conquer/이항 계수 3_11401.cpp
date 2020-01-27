#include <iostream>
#include <cmath>
using namespace std;
#define MAX 4000000 + 1
#define mod 1000000007
long long dp[MAX];
// �丣���� ������ : p�� �Ҽ��̰�, a�� p�� ����� �ƴϸ� a^(p-1)%p = 1�̴�.
// nCk = n! * ((k!) * (n-k)!)^-1. ��� ���� mod�� �������� �� �ִ�. 
// (k! * (n-k)!)^(mod-1) % mod = 1�̹Ƿ� �����ش�.
// �׷� (n! % mod * (k! * (n-k)!)^mod-2 % mod) % mod�� ���ϸ� �ȴ�.
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    int n, k;
    cin >> n >> k;
    // factorial ���ϱ�
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] * i) % mod;
    long long b = (dp[k] * dp[n - k]) % mod;
    // b�� mod - 2�� ���ϱ� (���� ���� ���)
    // Ȧ���� ���� C^n = C^(n-1)/2 * C^(n-1)/2 * C�̰� (�ϳ��� ���� �� ������ �� �� �� �� ����
    // ¦���� ���� C^n = C^(n/2) * (n/2) �̴�.
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