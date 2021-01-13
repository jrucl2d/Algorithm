#include <iostream>
using namespace std;
typedef long long ll;

class Runner {
public:
	ll value;
	int position;
	int npos;
	Runner() {
		this->value = 0;
		this->position = 0;
		this->npos = 0;
	};
	Runner(ll value, int position, int npos) {
		this->value = value;
		this->position = position;
		this->npos = npos;
	}
};

int n;
Runner v[500001];
Runner sv[500001];
ll ans[500001];


void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	
	while (i <= mid && j <= right) {
		if (v[i].value >= v[j].value) {
			sv[k++] = v[i++];
		}
		else {
			sv[k++] = v[j++];
			sv[k - 1].npos -= (j - k);
			ans[sv[k - 1].position] = sv[k - 1].npos;
		}
	}
	if (i > mid) {
		for (int a = j; a <= right; a++) {
			sv[k++] = v[a];
		}
	}
	else {
		for (int a = i; a <= mid; a++) {
			sv[k++] = v[a];
		}
	}

	for (int a = left; a <= right; a++) {
		v[a] = sv[a];
	}	
}

void merge_sort(int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		v[i] = (Runner(tmp, i, i));
		sv[i] = (Runner()); // dummy value
		ans[i] =(i);
	}
	merge_sort(0, n - 1);

	for (int i = 0; i < n; i++) {
		cout <<ans[i] + 1<< "\n";
	}

	return 0;
}