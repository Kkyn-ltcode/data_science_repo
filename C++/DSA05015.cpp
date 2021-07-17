#include <iostream>
#include <vector>
using namespace std;
#define r 1000000007

long long dp(int n, int k)
{
	vector<vector<long long>>p(n + 1, vector<long long>(k + 1, 1));
	for (int j = 1; j <= k; j++)
		p[n][j] = (p[n][j - 1] * (n - j + 1)) % r;
	return p[n][k];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << dp(n, k) << endl;
	}
	return 0;
}