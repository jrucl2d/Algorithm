#include <iostream> 
#include <algorithm>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	// n�� m�� ����ϸ� n+m-k/3 -> ��� �ο�(n+m-k)�� �� �� 1:2�� ������ ������ �ϹǷ�
	// n�� ũ�� n+m-k/3�� m�� ��
	// m�� ũ�� n+m-k/3�� n/2�� ��
	cout << min(min((n + m - k) / 3, m), n / 2);
}