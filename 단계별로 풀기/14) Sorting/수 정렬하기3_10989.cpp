#include <iostream> // ī����(���)����
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10001 //10,000���� �۰ų� �����Ƿ�
int cnt[MAX];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int tmp;
	while (n-- > 0) {
		cin >> tmp;
		cnt[tmp]++; // ���� ������ Ƚ���� ����
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < cnt[i]; j++)
			cout << i << '\n'; // i�� �����ϸ� �� Ƚ����ŭ ���
	}
}