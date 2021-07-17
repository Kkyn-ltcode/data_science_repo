#include <iostream>
#include <vector>
using namespace std;

int dp() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] %= k;
	}
	vector<int>lsc(k, INT_MIN), tmp(k);
	//lcs: longgest subarray with i surplus (i < k)
	lsc[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			tmp[j] = max(lsc[j], lsc[(j - a[i] + k) % k] + 1);
		lsc.swap(tmp);
	}
	return lsc[0];
}

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		cout << dp() << endl;
	}
	return 0;
}
/*
2
10 3
2 3 5 7 9 6 12 7 11 15
*/