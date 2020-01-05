#include <iostream> // 합병정렬 (분할정복 알고리즘)
using namespace std;
#define MAX 1000000
int v[MAX];
int sorted[MAX]; // 추가 메모리 필요
void merge(int* v, int left, int mid, int right) { // 합병하는 함수
	int i, j, k;
	k = i = left; // 좌측 담당
	j = mid + 1; // 우측 담당
	while (i <= mid && j <= right) { // left나 right 둘 중 작은게 끝날 때까지
		if (v[i] <= v[j])
			sorted[k++] = v[i++];
		else
			sorted[k++] = v[j++];
	}
	if (i > mid) { // 좌측 끝. 우측에 남은 것 처리
		for (int m = j; m <= right; m++)
			sorted[k++] = v[m];
	}
	else { // 우측 끝. 좌측에 남은 것 처리
		for (int m = i; m <= mid; m++)
			sorted[k++] = v[m];
	}
	for (int m = left; m <= right; m++)
		v[m] = sorted[m]; // 정렬된 배열로 바꾸기
}
void mergeSort(int* v, int left, int right) { // 분할 정복이 이루어짐
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