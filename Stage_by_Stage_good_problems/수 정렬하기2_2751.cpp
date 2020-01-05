#include <iostream> // �պ����� (�������� �˰���)
using namespace std;
#define MAX 1000000
int v[MAX];
int sorted[MAX]; // �߰� �޸� �ʿ�
void merge(int* v, int left, int mid, int right) { // �պ��ϴ� �Լ�
	int i, j, k;
	k = i = left; // ���� ���
	j = mid + 1; // ���� ���
	while (i <= mid && j <= right) { // left�� right �� �� ������ ���� ������
		if (v[i] <= v[j])
			sorted[k++] = v[i++];
		else
			sorted[k++] = v[j++];
	}
	if (i > mid) { // ���� ��. ������ ���� �� ó��
		for (int m = j; m <= right; m++)
			sorted[k++] = v[m];
	}
	else { // ���� ��. ������ ���� �� ó��
		for (int m = i; m <= mid; m++)
			sorted[k++] = v[m];
	}
	for (int m = left; m <= right; m++)
		v[m] = sorted[m]; // ���ĵ� �迭�� �ٲٱ�
}
void mergeSort(int* v, int left, int right) { // ���� ������ �̷����
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(v, left, mid);
		mergeSort(v, mid + 1, right);
		merge(v, left, mid, right);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	mergeSort(v, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d\n", v[i]);
}