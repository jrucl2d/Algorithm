#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;
// ������ �����ִ� ���� b�� ���� ������ �Ŵϱ�
// a�� b�� ���� ��ü�� ��ü ���̿� ����.
int main() {
	string a, b;
	cin >> a >> b;
	int resultMin = 50;
	int count = 0;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		for (int j = i; j < i + a.length(); j++) {
			if (a[j-i] != b[j]) count++;
		}
		resultMin = min(count, resultMin);
		count = 0;
	}
	cout << resultMin;
}