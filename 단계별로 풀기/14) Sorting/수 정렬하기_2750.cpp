#include <iostream>
using namespace std;
#define MAX 1000
int v[1000];
void sort(int* v, int size) {
	int key;
	int i, j; // j ���� ����ϱ� ���� �̸� ����
	for (i = 1; i < size; i++) { // ù ��°�� �̹� ���ĵ� ������ ����.
		key = v[i]; // �̹��� �����ؾ� �� ���
		for (j = i - 1; j >= 0 && v[j] > key; j--) { // ���� ��ҵ��� ��� ����(key���� ū ��� �ڷ� �̷��)
			v[j + 1] = v[j];
		}
		v[j + 1] = key; // �̷�� �������� j-- �����ϹǷ� j+1 �ڸ��� key�� ����
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