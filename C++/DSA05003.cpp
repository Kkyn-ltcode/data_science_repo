#include <iostream>
#include <vector>
using namespace std;

int dp(string s1, string s2, string s3, int n1, int n2, int n3)
{
	vector<vector<vector<int>>>lcs
	(n1 + 1, vector<vector<int>>
		(n2 + 1, vector<int>(n3 + 1, 0)));
	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
		{
			for (int k = 1; k <= n3; k++)
			{
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
					lcs[i][j][k] = 1 + lcs[i - 1][j - 1][k - 1];
				else
					lcs[i][j][k] = max(max(lcs[i - 1][j][k], lcs[i][j - 1][k]),
						lcs[i][j][k - 1]);
			}
		}
	}
	return lcs[n1][n2][n3];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		cout << dp(s1, s2, s3, n1, n2, n3) << endl;
	}
	return 0;
}