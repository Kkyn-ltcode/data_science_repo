#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>b)
{
	for (int i = 0; i < b.size(); i++)
	{
		if (i == 0)
			cout << "[";
		if (i == b.size() - 1)
			cout << b[i] << "] ";
		else
			cout << b[i] << " ";
	}
}

void back_track(int i, vector<int>a, int n)
{
	vector<int>b = a;
	for (int k = 0; k < b.size() - 1; k++)
		b[k] = b[k] + b[k + 1];
	b.pop_back();
	if (i == n - 1)
	{
		print(b);
		return;
	}
	else
		back_track(i + 1, b, n);
	print(b);
}

int main()
{
	int t;
	cin >> t;
	for (int m = 0; m < t; m++)
	{
		int n;
		cin >> n;
		vector<int>a;
		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			a.push_back(v);
		}
		back_track(1, a, n);
		print(a);
		cout << endl;
	}
	return 0;
}