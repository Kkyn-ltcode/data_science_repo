#include <iostream>
#include <vector>
using namespace std;

long long find(vector<long long> a, long long left, long long right, long long k)
{
	if (left > right)
		return -1;
	long long mid = (left + right) / 2;
	if (a[mid] == k)
		return mid + 1;
	if (a[mid] > k)
		return find(a, 0, mid - 1, k);
	return find(a, mid + 1, right, k);
}

int main()
{
	int t;
	cin >> t;
	for (int x = 0; x < t; x++)
	{
		long long n, k;
		cin >> n >> k;
		vector<long long>a;
		for (long long i = 0; i < n; i++)
		{
			long long v;
			cin >> v;
			a.push_back(v);
		}
		long long res = find(a, 0, n - 1, k);
		if (res != -1)
			cout << res << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}