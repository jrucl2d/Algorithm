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

int func(int i, int w) {							// ��������� �ε���, ���� ���� ������ �Ķ����, ��ġ�� ����

	if (dp[i][w] > 0) return dp[i][w];				// ���� �ش� dp�� ���ǵ� ���� �ִٸ� �װ��� �����ض�.
	if (i == n)										// Ż�� ����. i�� n�� �������� ���� �ε����� ������ �����̹Ƿ� ����.
		return 0;
	int r1 = 0;
	if (w + weight[i] <= k) {						// ���±����� ���Կ� ���� ���Ը� ���� ���� k���� ������ ���					
		r1 = value[i] + func(i + 1, w + weight[i]); // ������ ������ �������� ���. ����(i)�� ��ġ + ���� �ε���, 
													// ���ݱ����� ����(w)�� ���� ���Ը� ���� �� �Ѱ���.
	}						
	int r2 = 0 + func(i + 1, w + 0); 				// ������ ������ �� �������� ���. ������ ��ġ�� ������ ���Ը� �����ִ� �κ��� ����.
	return dp[i][w] = max(r1, r2);					// �� �� �ִ밪�� ����.
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