#include <iostream> // 선택정렬
using namespace std;
#define MAX 1000
int v[1000];
void sort(int* v, int size) {
	int min; // 최소값을 저장할 인덱스
	int tmp;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) { // 이후부터 최소값을 찾음
			if (v[j] < v[min])
				min = j;
		}
		// swap 진행
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