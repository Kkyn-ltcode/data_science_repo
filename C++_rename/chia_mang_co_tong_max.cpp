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
		int n, k;
		cin >> n >> k;
		vector<int>a;
		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			a.push_back(v);
		}
		sort(a.begin(), a.end(), greater<int>());
		long long s = 0, s1 = 0;
		for (int i = 0; i < n; i++)
			s += a[i];
		int M = max(k, n - k);
		for (int i = 0; i < M; i++)
			s1 += a[i];
		cout << 2 * s1 - s << endl;
	}
	return 0;
}