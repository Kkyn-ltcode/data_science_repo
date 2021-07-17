#include <iostream>
#include <vector>
using namespace std;
long long r = 1e9 + 7;

long long dp(vector<long long>x, vector<long long>a,
	int n, int k) {
	for (int sub_sum = 1; sub_sum <= k; sub_sum++) {
		x[sub_sum] = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] <= sub_sum) {
				x[sub_sum] += x[sub_sum - a[i]];
				x[sub_sum] %= r;
			}
		}
	}
	return x[k];
}

long long driver() {
	int n, k;
	cin >> n >> k;
	vector<long long>x(n + 1, 1);
	vector<long long>a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// x[i] stores number of ways of array elements
	// whose sum equal k
	return dp(x, a, n, k);
}

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		cout << driver() << endl;
	}
	return 0;
}
