#include <iostream> // ��������
using namespace std;
#define MAX 1000
int v[1000];
void sort(int* v, int size) {
	int tmp; // ū �ݺ� �� ������ ������ �� ���� �ִ밪�� ���� ��
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) { // ��ü
				tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v, n);
	for (int i = 0; i < n; i++)
		cout << v[i] << endl;
}