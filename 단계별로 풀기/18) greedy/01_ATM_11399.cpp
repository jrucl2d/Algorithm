#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num_person;
	cin >> num_person;
	int *time = new int[num_person];
	for (int i = 0; i < num_person; i++)
		cin >> time[i];
	sort(time, time + num_person); // ¿À¸§Â÷¼øÀ¸·Î sort
	int sum = 0;
	for (int i = 0; i < num_person; i++) {
		for (int j = 0; j <= i; j++) {
			sum += time[j];
		}
	}
	delete(time);
}
