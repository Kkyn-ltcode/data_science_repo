#include <iostream>
#include <vector>
using namespace std;

long long divide(vector<long long>a, long long left,
	long long right, long long k)
{
	if (left > right)
		return -1;
	if (k >= a[right])
		return right;
	int mid = (left + right) / 2;
	if (a[mid] == k)
		return mid;
	if (mid > 0 && a[mid - 1] <= k && k < a[mid])
		return mid - 1;
	if (a[mid] > k)
		return divide(a, left, mid - 1, k);
	return divide(a, mid + 1, right, k);
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
			int v;
			cin >> v;
			a.push_back(v);
		}
		long long ans = divide(a, 0, n - 1, k);
		if (ans != -1)
			cout << ans + 1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}