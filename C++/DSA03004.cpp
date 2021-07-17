#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int m = 0; m < t; m++)
	{
		int n;
		cin >> n;
		vector<int>a;
		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			a.push_back(v);
		}
		sort(a.begin(), a.end());
		long long x = 0, y = 0;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 != 0)
				x = x * 10 + a[i];
			else
				y = y * 10 + a[i];
		}
		cout << x + y << endl;
	}
	return 0;
}