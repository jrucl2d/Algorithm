#include <iostream> 
#include <string>
using namespace std;
// ó���� �� �����ִٰ� ó�� '-' ���� �������� �� ���ֱ�
int main() {
	string sik;
	cin >> sik;
	bool minus = false;
	int sum = 0;
	string tmp;
	for (int i = 0; i <= sik.length(); i++) { // length�� ���̸� return�ϹǷ� ���� NULL�� �ľ��ϱ� ����
		if (sik[i] == '+' || sik[i] == '-' || sik[i] == '\0') { // ������ �����ų� ���̸�
			if (minus) {
				sum -= stoi(tmp);
			}
			else {
				sum += stoi(tmp);
			}
			tmp = ""; // tmp �ʱ�ȭ
			if (sik[i] == '-')
				minus = true;
			continue; // �ǳʶٱ�
		}	
		else
			tmp += sik[i];
	}
	cout << sum;
}