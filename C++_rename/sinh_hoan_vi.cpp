#include <iostream>
#include <vector>
using namespace std;
vector<int>a, unused;
int n;

void input()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		unused.push_back(1);
		a.push_back(1);
	}
}

void result()
{
	for (int i = 1; i <= n; i++)
		cout << a[i];
	cout << " ";
}

void nextGen(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (unused[j] == 1)
		{
			a[i] = j;
			unused[j] = 0;
			if (i == n)
				result();
			else
				nextGen(i + 1);
			unused[j] = 1;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		input();
		nextGen(1);
		cout << endl;
		unused.clear();
		a.clear();
	}
	return 0;
}