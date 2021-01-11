#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a, b, v;
	cin >> a >> b >> v;
	int go = a - b; // (a-b)*(n-1) + a >= v
	if((v-a)%go == 0) printf("%d", (v - a) / go + 1);
	else printf("%d", (v - a) / go + 1 + 1); // (v-a) / go가 하나 작으므로 
}