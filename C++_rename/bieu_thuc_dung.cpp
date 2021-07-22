#include <iostream>
#include <vector>
using namespace std;

void greedy(string s)
{
	vector<int>pos;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '[')
			pos.push_back(i);
	int c = 0, p = 0, res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '[')
		{
			p++;
			c++;
		}
		else if (s[i] == ']')
			c--;
		if (c < 0)
		{
			res += pos[p] - i;
			swap(s[i], s[pos[p]]);
			p++;
			c = 1;
		}
	}
	cout << res << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int x = 0; x < t; x++)
	{
		string s;
		cin >> s;
		greedy(s);
	}
	return 0;
}