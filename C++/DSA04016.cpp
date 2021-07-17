#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int x = 0; x < t; x++)
	{
		long long m, n, k;
		cin >> m >> n >> k;
		vector<long long>a;
		for (long long i = 0; i < m + n; i++)
		{
			long long v;
			cin >> v;
			a.push_back(v);
		}
		sort(a.begin(), a.end());
		cout << a[k - 1] << endl;
	}
	return 0;
}