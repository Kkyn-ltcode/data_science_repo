#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	vector<int>money = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };
	for (int x = 0; x < t; x++)
	{
		int n, c = 0;
		cin >> n;
		for (int i = money.size() - 1; i >= 0; i--)
		{
			while (n >= money[i] && n > 0)
			{
				n = n - money[i];
				c++;
			}
		}
		cout << c << endl;
	}
}