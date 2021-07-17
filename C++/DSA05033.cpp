#include <iostream>
#include <vector>
using namespace std;

int dp(string s)
{
	vector<vector<int>>x(s.size(), vector<int>(s.size(), 0));
	int i, j;
	for (int diff = 1; diff < s.size(); diff++)
	{
		for (i = 0, j = diff; j < s.size(); i++, j++)
		{
			if (s[i] == s[j])
				x[i][j] = x[i + 1][j - 1];
			else
				x[i][j] = min(x[i + 1][j], x[i][j - 1]) + 1;
		}
	}
	return x[0][s.size() - 1];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << dp(s) << endl;
	}
	return 0;
}