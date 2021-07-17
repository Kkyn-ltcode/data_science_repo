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
		long long n, m;
		cin >> n >> m;
		vector<long long>a;
		for (long long i = 0; i < n; i++)
		{
			long long v;
			cin >> v;
			a.push_back(v);
		}
		for (long long i = 0; i < m; i++)
		{
			long long v;
			cin >> v;
			a.push_back(v);
		}
		sort(a.begin(), a.end());
		for (long long i = 0; i < m + n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}