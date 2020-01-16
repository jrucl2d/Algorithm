#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 100 + 1
#define wMax 100000 + 1

int n, k;
int value[MAX];
int weight[MAX];
int dp[MAX][wMax]; // i, w

int func(int i, int w) {							// 현재까지의 인덱스, 현재 무게 순으로 파라미터, 가치를 리턴

	if (dp[i][w] > 0) return dp[i][w];				// 만약 해당 dp에 정의된 값이 있다면 그것을 리턴해라.
	if (i == n)										// 탈출 조건. i가 n과 같아지면 끝의 인덱스에 도달한 다음이므로 리턴.
		return 0;
	int r1 = 0;
	if (w + weight[i] <= k) {						// 여태까지의 무게에 현재 무게를 더한 값이 k보다 이하인 경우					
		r1 = value[i] + func(i + 1, w + weight[i]); // 현재의 물건을 가져갔을 경우. 현재(i)의 가치 + 다음 인덱스, 
													// 지금까지의 무게(w)에 현재 무게를 더한 것 넘겨줌.
	}						
	int r2 = 0 + func(i + 1, w + 0); 				// 현재의 물건을 안 가져갔을 경우. 현재의 가치와 현재의 무게를 더해주는 부분이 없다.
	return dp[i][w] = max(r1, r2);					// 둘 중 최대값을 리턴.
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	
	int w, v;
	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> value[i];
	}
	cout << func(0, 0);
}