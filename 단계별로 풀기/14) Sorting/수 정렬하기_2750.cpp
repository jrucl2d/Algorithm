#include <iostream>
using namespace std;
#define MAX 1000
int v[1000];
void sort(int* v, int size) {
	int key;
	int i, j; // j 값을 기억하기 위해 미리 선언
	for (i = 1; i < size; i++) { // 첫 번째는 이미 정렬된 것으로 본다.
		key = v[i]; // 이번에 정렬해야 될 요소
		for (j = i - 1; j >= 0 && v[j] > key; j--) { // 이전 요소들을 모두 정렬(key보다 큰 경우 뒤로 미루기)
			v[j + 1] = v[j];
		}
		v[j + 1] = key; // 미루고 마지막에 j-- 실행하므로 j+1 자리에 key값 삽입
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