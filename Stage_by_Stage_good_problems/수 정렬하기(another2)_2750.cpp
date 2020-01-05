#include <iostream> // 버블정렬
using namespace std;
#define MAX 1000
int v[1000];
void sort(int* v, int size) {
	int tmp; // 큰 반복 한 번마다 오른쪽 맨 끝에 최대값이 오게 됨
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) { // 교체
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