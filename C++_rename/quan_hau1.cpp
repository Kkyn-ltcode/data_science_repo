#include <iostream>
using namespace std;
int a[100], lt[100], rt[100], unused[100], n, c;

void init()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		unused[i] = true;
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		lt[i] = true;
		rt[i] = true;
	}
}

void back_track(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (unused[j] && lt[i - j + n] && rt[i + j - 1])
		{
			a[i] = j;
			unused[j] = false;
			lt[i - j + n] = false;
			rt[i + j - 1] = false;
			if (i == n)
				c++;
			else
				back_track(i + 1);
			unused[j] = true;
			lt[i - j + n] = true;
			rt[i + j - 1] = true;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int x = 0; x < t; x++)
	{
		c = 0;
		init();
		back_track(1);
		cout << c << endl;
	}
	return 0;
}