#include <iostream> // ��������
using namespace std;
#define MAX 1000
int v[1000];
void sort(int* v, int size) {
	int min; // �ּҰ��� ������ �ε���
	int tmp;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) { // ���ĺ��� �ּҰ��� ã��
			if (v[j] < v[min])
				min = j;
		}
		// swap ����
		tmp = v[i];
		v[i] = v[min];
		v[min] = tmp;
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