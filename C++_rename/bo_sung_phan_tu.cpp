#include <iostream>
#include <set>
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
		set<long long>a;
		for (long long i = 0; i < n; i++)
		{
			long long v;
			cin >> v;
			a.insert(v);
		}
		set<long long>::iterator it = a.begin();
		long long l = *it;
		while (it != a.end())
			it++;
		it--;
		long long r = *it;
		cout << r - l + 1 - a.size() << endl;
	}
	return 0;
}