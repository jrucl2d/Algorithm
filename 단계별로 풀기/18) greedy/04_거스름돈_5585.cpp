#include <iostream> 
using namespace std; // ³Ê¹« ½¬¿î ¹®Á¦

int main() {
	int total = 1000;
	int pay, remain;
	cin >> pay;
	remain = total - pay; // ÀÜµ·
	int count = 0;
	int money[6] = { 500,100,50,10,5,1 };
	for (int i = 0; i < 6; i++) {
		count += remain / money[i];
		remain = remain % money[i];
	}
	cout << count;
}
