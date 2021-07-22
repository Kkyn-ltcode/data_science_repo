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
		long long n;
		cin >> n;
		vector<long long>a, b;
		for (long long i = 0; i < n; i++)
		{
			long long v;
			cin >> v;
			a.push_back(v);
		}
		b = a;
		sort(b.begin(), b.end());
		for (long long i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				cout << i + 1 << " ";
				break;
			}
		}
		for (long long i = n - 1; i >= 0; i--)
		{
			if (a[i] != b[i])
			{
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}