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
		vector<long long>a, b;
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
			b.push_back(v);
		}
		sort(a.begin(), a.end(), greater<long long>());
		sort(b.begin(), b.end());
		cout << a[0] * b[0] << endl;
	}
	return 0;
}