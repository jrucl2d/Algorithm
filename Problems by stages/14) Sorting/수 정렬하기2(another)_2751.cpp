#include <iostream> // �պ����� (�������� �˰���)
using namespace std;
#define MAX 1000000
#define swap(a, b, tmp) ((tmp) = (a), (a) = (b), (b) = (tmp))
int v[MAX];
// ���� ���ڵ��� ���ĵǴ� ����
int partition(int* v, int left, int right) {
	int pivot, tmp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = v[left]; // ���� ���� ������ ���� ����
	do { // low > high�� �Ǳ� ������(�����ϱ� ������) �ݺ�
		do {
			low++; // v[low]�� �ǹ����� ������ ��� low ����
		} while (low <= right && v[low] < pivot);
		do {
			high--; // v[high]�� �ǹ����� ũ�� ��� high ����
		} while (high >= left && v[high] > pivot);

		if (low < high)  // ���� �������� �ʾҴµ� ������(���� �ش� �� �Ǵ� ���� ã������)
			swap(v[low], v[high], tmp); // swap ����
	} while (low < high);

	// low�� high�� �����ؼ� ������ left ���� high ���� �ٲ㼭 �ǹ��� �߰��� ������ ��
	swap(v[left], v[high], tmp);
	return high; // �߰��� �ִ� �ǹ��� ��ġ�� ��ȯ
}
void quickSort(int* v, int left, int right) {
	if (left < right) {
		int pivot = partition(v, left, right); // �ǹ� ���
		quickSort(v, left, pivot - 1); // �ǹ��� ������ �� ���� �ٽ� ����
		quickSort(v, pivot + 1, right);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	quickSort(v, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d\n", v[i]);
}