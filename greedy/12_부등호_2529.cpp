#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, in1[10], in2[10], MIN[10], MAX[10];
char c;
vector<int> e[10];
string minResult, maxResult;
int main() {
    // n�� �ε�ȣ�� �Է� ����
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == '<') { // i < i+1 �̶��
            e[i + 1].push_back(i); // i+1�� ����� �� �� �ϳ��� i�̴�.
            in1[i]++, in2[i]++; // i�� ������ �����Ѵ�.
        }
        else { // i > i+1 �̶��
            e[i].push_back(i + 1); // i�� ����� �� �� �ϳ��� i+1�̴�.
            in1[i + 1]++, in2[i + 1]++; // i+1�� ������ �����Ѵ�.
        }
    } // ��������� max�� �� ���� ������ ���� �ȴ�. 
    //for (int i = 0; i <= n; i++)
    //    cout << in1[i] << " ";
    //cout << endl;
    //for (int i = 0; i <= n; i++)
    //    cout << in2[i] << " ";
    for (int i = 0; i <= n; i++) { // �� n�� �ݺ�
        for (int j = 0; j <= n; j++) {
            if (!in1[j]) {
                MAX[j] = 9 - i, in1[j] = 100; // ������ ln1[j]�� �� �ɸ����� ���� �ٲ���
                for (int k = 0; k < e[j].size(); k++) in1[e[j][k]]--; // j�� ������ ����� �� ������ ����
                break;
            }
        }
        for (int j = n; j >= 0; j--) { // ���� �׷����� �Ʒ������� �Ȱ� ���� ���̴�.
            if (!in2[j]) { // �׷����� ���� ����� ����, ������ �ȴ��� �Ʒ����� �ȴ����� �ٸ���.
                MIN[j] = n - i, in2[j] = 1;
                for (int k = 0; k < e[j].size(); k++) in2[e[j][k]]--;
                break;
            }
        }
    }
    for (int i = 0; i <= n; i++) { 
        maxResult += MAX[i] + '0';
        minResult += MIN[i] + '0';
    }
    cout << maxResult << endl << minResult;
}