#include <iostream> // 합병정렬 (분할정복 알고리즘)
using namespace std;
#define MAX 1000000
#define swap(a, b, tmp) ((tmp) = (a), (a) = (b), (b) = (tmp))
int v[MAX];
// 실제 숫자들이 정렬되는 과정
int partition(int* v, int left, int right) {
	int pivot, tmp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = v[left]; // 제일 왼쪽 것으로 임의 설정
	do { // low > high가 되기 전까지(교차하기 전까지) 반복
		do {
			low++; // v[low]가 피벗보다 작으면 계속 low 증가
		} while (low <= right && v[low] < pivot);
		do {
			high--; // v[high]가 피벗보다 크면 계속 high 감소
		} while (high >= left && v[high] > pivot);

		if (low < high)  // 아직 교차하지 않았는데 끝나면(조건 해당 안 되는 놈이 찾아지면)
			swap(v[low], v[high], tmp); // swap 실행
	} while (low < high);

	// low와 high가 교차해서 끝나면 left 값과 high 값을 바꿔서 피벗을 중간에 오도록 함
	swap(v[left], v[high], tmp);
	return high; // 중간에 있는 피벗의 위치를 반환
}
void quickSort(int* v, int left, int right) {
	if (left < right) {
		int pivot = partition(v, left, right); // 피벗 계산
		quickSort(v, left, pivot - 1); // 피벗을 제외한 양 옆을 다시 분할
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