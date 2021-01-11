#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define MAX 15

ll dp[1 << MAX][101]; // i 상태의 수가 골라졌을 때 나머지가 j인 경우의 수.(1101이면, 3번,2번,0번 수를 이용해 나머지가 j인 수가 만들어지는 경우의 수)
string num[MAX]; // 최초에 숫자를 입력받을 배열
int len[MAX]; // 입력받은 숫자의 길이를 저장할 배열
int mod[MAX]; // i번째 수를 k로 나눈 모듈러 값
int ten[51]; // 수가 최대 50자리의 수이므로 10의 i승의 k모듈러 값이 저장된다.

int n, k;

ll gcd(ll x, ll y) { // 최대 공약수를 구하는 유클리드 알고리즘
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		len[i] = num[i].size(); // 입력받은 숫자의 길이를 저장한다.
	}
	cin >> k;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len[i]; j++) { // 각 수에 대해서 그 길이만큼 반복
			// string 형태로 있던 수를 int형으로 바꾸면서 mod 연산을 수행
			mod[i] = mod[i] * 10 + (num[i][j] - '0');
			mod[i] %= k;
		}
	} // 결론적으로 mod 배열에는 string으로 되어있던 수들의 int형 k 모듈러 값이 저장된다.

	ten[0] = 1; // '10의 i승' <- 이 수의 k 모듈러 값을 배열에 저장
	for (int i = 1; i <= 50; i++) {
		ten[i] = ten[i - 1] * 10;
		ten[i] %= k;
	}
	dp[0][0] = 1; // 수가 안 골라졌을 때 나머지가 0일 확률은 1이다.
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < n; l++) {
				// 현재 상태가 i이고, 나머지가 j이면 i에서 포함되지 않은 l번 수를 뒤에 이어 붙였을 때의 나머지를 next라고 하자.
				// 그러면 dp[i|(1<<l)][next] += dp[i][j]이다. i|(1<<l)는 현재 사용된 수의 위치가 1로 나타내져있고, 새로 더할 
				// 수 l의 위치와 or 연산을 취하면 상태 비트에 기존 i에 새로운 l의 위치가 더해진 새로운 상태가 나온다. 그 상태의 
				// 나머지를 next라고 가정했으므로 dp[i|(1<<l)][next]의 식이 나온다. 이 기존 값에 dp[i][j]를 더한 값이 결과이다.
				// next = (새로운 수)%k = (원래 수 * pow(10,len(l번째수)) + l번째 수) % k이다. 이것은 원래 수를 l의 길이만큼
				// 왼쪽으로 밀고 오른쪽에 l의 수를 붙이는 작업이다. 여기서 %k를 식 안으로 넣어주면
				// [(원래수%k * pow(10,len(l번째수))%k)%k + l번째수 % k] % k이다. 여기서 원래수 % k 가 바로 나머지 j이다.
				// 따라서 식은 [j*pow(10,len(l번째수))%k) %k + l번째수 %k] %k이다.

				if ((i & (1 << l)) == 0) { // 현재 i상태에서 l의 비트와 and 연산했을 때 0이면 아직 l이 사용되지 않았다는 의미이다.
					int next = j * ten[len[l]]; // 이 식이 바로 위 식에서 j*pow(10,len(l번째수))%k 이다.
					next %= k; // 이 뒤에 다시 %k를 하고 마지막으로 + l번째수 %k를 해주고 마지막에 %k하면 된다.
					next += mod[l]; // 여기가 바로 l번째수 %k를 더해주는 부분.
					next %= k; // 마지막 %k 연산.
					dp[i | (1 << l)][next] += dp[i][j]; // 위의 식을 코드로 그대로 작성한 모습.
				}
			}
		}
	}
	// 우리가 구해야 할 모든 수 n에 대해서 경우의 수를 구한 것. 1<<n이 (n+1)자리에 1 있고 나머지 0이므로 여기서 -1하면 n자리 전체 1인 경우이다.
	// 그리고 여기서 k로 나누어떨어지는 경우의 수이므로 나머지가 0인경우를 구해야 한다.
	ll up = dp[(1 << n) - 1][0]; // 즉 이것이 분자
	// 분모는 n개로 만들 수 있는 순열의 수이므로 n!이다. 
	ll down = 1;
	for (ll i = 2; i <= n; i++)
		down *= i; // 결론적으로 분모에 들어간다.
	ll divide = gcd(up, down); // 기약분수를 만들기 위해 최대공약수를 구한다.
	up /= divide;
	down /= divide;
	cout << up << "/" << down << "\n";
}