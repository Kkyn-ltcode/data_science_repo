#include <iostream>
#include <vector>
using namespace std;

long long dp(vector<vector<long long>>x, int n, int m) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			x[i][j] = x[i - 1][j] + x[i][j - 1];
	return x[n][m];
}

long long driver() {
	int n, m;
	cin >> n >> m;
	vector<vector<long long>>x(n + 1, vector<long long>(m + 1, 1));
	// x[i][j] stores number of ways to arrive O(0, 0)
	// from A(i, j)
	return dp(x, n, m);
}

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		cout << driver() << endl;
	}
	return 0;
}
