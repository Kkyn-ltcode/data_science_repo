#include <iostream>
using namespace std;
int a[100][100], n;
char b[100];
bool printed;

void init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

void print(int k)
{
	for (int i = 0; i < k; i++)
		cout << b[i];
	cout << " ";
	printed = true;
}

void back_track(int i, int j, int k)
{
	if (i == n - 1 && j == n - 1)
	{
		print(k);
		return;
	}
	if (i + 1 < n && a[i + 1][j] == 1)
	{
		b[k] = 'D';
		back_track(i + 1, j, k + 1);
	}
	if(j + 1 < n && a[i][j + 1] == 1)
	{
		b[k] = 'R';
		back_track(i, j + 1, k + 1);
	}
}

int main()
{
	int t;
	cin >> t;
	for (int x = 0; x < t; x++)
	{
		init();
		printed = false;
		if (a[0][0] != 1)
			cout << "-1";
		else
		{
			back_track(0, 0, 0);
			if (!printed)
				cout << "-1";
		}
		cout << endl;
	}
	return 0;
}