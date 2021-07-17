#include <iostream>
#include <vector>
#define huge unsigned long long int
using namespace std;
huge r = 1e9 + 7;

vector<vector<huge>>x(101, vector<huge>(50001, -1));
// x[n][sum] is number of n digits number whose sum
// of digits equals to sum
huge dp(int n, int sum) {
	if (n == 0)
		return sum == 0;
	if (x[n][sum] != -1)
		return x[n][sum];
	huge ans = 0;
	for (int i = 0; i <= 9; i++) {
		if (sum - i >= 0) {
			ans += dp(n - 1, sum - i);
			ans %= r;
		}
	}
	return x[n][sum] = ans;
}

huge driver() {
	int n, sum;
	cin >> n >> sum;
	huge ans = 0;
	for (int i = 1; i <= 9; i++) {
		if (sum - i >= 0) {
			ans += dp(n - 1, sum - i);
			ans %= r;
		}
	}
	return ans;
}

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		cout << driver() << endl;
	}
	return 0;
}
