#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define r 1000000007

int main()
{
	int t;
	cin >> t;
	for (int x = 0; x < t; x++)
	{
		int n;
		long long s = 0;
		cin >> n;
		vector<int>a;
		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			a.push_back(v);
		}
		sort(a.begin(), a.end());
		for (int i = 1; i < n; i++)
			s += a[i] * i;
		cout << s % r << endl;
	}
	return 0;
}