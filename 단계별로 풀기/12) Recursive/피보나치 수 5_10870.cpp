#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int cal(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n >= 2)
        return cal(n - 1) + cal(n - 2);
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << cal(n);
}