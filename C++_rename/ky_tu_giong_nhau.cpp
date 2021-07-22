#include <iostream>
#include <vector>
using namespace std;

int dp(int n, int insert, int remove, int copy)
{
	vector<int>x(n + 1, 0);
	x[1] = insert;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
			x[i] = min(x[i / 2] + copy, x[i - 1] + insert);
		else
			x[i] = min(x[i - 1] + insert, x[i / 2 + 1] + copy + remove);
	}
	return x[n];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, insert, copy, remove;
		cin >> n >> insert >> remove >> copy;
		cout << dp(n, insert, remove, copy) << endl;
	}
	return 0;
}