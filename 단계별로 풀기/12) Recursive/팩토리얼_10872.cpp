#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int fac(int n) {
    if (n < 2)
        return 1;
    else
        return n * fac(n - 1);
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << fac(n);
}