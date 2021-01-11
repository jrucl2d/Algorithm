#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Person {
public:
	int num;
	int count;
	int timestamp;
	
	Person(int num, int count, int timestamp) {
		this->num = num;
		this->count = count;
		this->timestamp = timestamp;
	}
};

bool myComp(const Person& a, const Person& b) {
	if (a.count < b.count) {
		return true;
	}
	else if (a.count == b.count) {
		if (a.timestamp < b.timestamp) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool ansComp(const Person& a, const Person& b) {
	if (a.num < b.num) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int n, pn;
	cin >> n;
	cin >> pn;
	vector<Person> candi;
	for (int i = 0; i < pn; i++) {
		int now = 0;
		cin >> now;
		bool exist = false;
		for (int j = 0; j < candi.size(); j++) {
			if (candi[j].num == now) {
				candi[j].count++;
				exist = true;
				break;
			}
		}
		if (exist) continue;
		if (candi.size() < n) {
			candi.push_back(Person(now, 1, i));
		}
		else {
			sort(candi.begin(), candi.end(), myComp);
			candi[0] = Person(now, 1, i);
		}
	}
	sort(candi.begin(), candi.end(), ansComp);
	for (int i = 0; i < n; i++) {
		cout << candi[i].num << " ";
	}
	cout << endl;

	return 0;
}
