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
//int cnt = 0; // 시간 단축 가능한 코드. cnt출력으로 시간 단축을 확인 가능
//void sort(int* v, int size) {
//	int tmp; // 큰 반복 한 번마다 오른쪽 맨 끝에 최대값이 오게 됨
//	bool nope = false;
//	for (int i = size - 1; i > 0; i--) {
//		while (!nope) {
//			nope = true;
//			for (int j = 0; j < i; j++) {
//				if (v[j] > v[j + 1]) { // 교체
//					tmp = v[j];
//					v[j] = v[j + 1];
//					v[j + 1] = tmp;
//					nope = false;
//				}
//			}
//			cnt++;
//		}
//	}
//}
