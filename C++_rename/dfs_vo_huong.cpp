#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>a, vector<bool> unused, int u)
{
	stack<int>s;
	s.push(u);
	unused[u] = false;
	cout << u << " ";
	while (!s.empty())
	{
		int st = s.top();
		s.pop();
		for (int i = 0; i < a[st].size(); i++)
		{
			if (unused[a[st][i]])
			{
				cout << a[st][i] << " ";
				unused[a[st][i]] = false;
				s.push(st);
				s.push(a[st][i]);
				break;
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int v, e, u, x1, x2;
		cin >> v >> e >> u;
		vector<vector<int>>a(v + 1, vector<int>());
		vector<bool>unused(v + 1, true);
		for (int i = 0; i < e; i++)
		{
			cin >> x1 >> x2;
			a[x1].push_back(x2);
			a[x2].push_back(x1);
		}
		DFS(a, unused, u);
		cout << endl;
	}
	return 0;
}
