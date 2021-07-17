#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int m = 0; m < t; m++)
	{
		int n;
		cin >> n;
		vector<long long>a;
		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			a.push_back(v);
		}
		long long s = 0;
		priority_queue<long long, vector<long long>, greater<long long>>pq(a.begin(), a.end());
		while (pq.size() > 1)
		{
			long long first = pq.top();
			pq.pop();
			long long second = pq.top();
			pq.pop();
			s += first + second;
			pq.push(first + second);
		}
		cout << s << endl;
	}
	return 0;
}