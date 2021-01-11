#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x1, x2, y1, y2, r1, r2;
    int t;
    cin >> t;
    vector<int>ans;
    while (t-- > 0) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        int shortR = min(r1, r2); //ª�� ������
        int longR = max(r1, r2); //�� ������

        if (distance <= longR) //�� �ȿ� �ٸ� ���� �߽��� ���� ���
        {
            if (x1 == x2 && y1 == y2 && r1 == r2) //�� �� ����
                ans.push_back(-1);
            else if (distance + shortR < longR) //������ ���� ���
                ans.push_back(0);
            else if (distance + shortR == longR) //�ϳ��� ����, ����
                ans.push_back(1);
            else if (distance + shortR > longR) //�� ���� ����
                ans.push_back(2);
        }
        else // �� �ۿ� �ٸ� ���� �߽��� ���� ���
        {
            if (distance > longR + shortR) //������ ���� ���
                ans.push_back(0);
            else if (distance == longR + shortR) //�Ѱ��� ����, ����
                ans.push_back(1);
            else if (distance < longR + shortR) //�ΰ��� ����
                ans.push_back(2);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}