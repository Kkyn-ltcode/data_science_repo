#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> a, vector<bool> &unused, int u)
{
	queue<int> q;
	q.push(u);
	unused[u] = true;
    cout << u + 1 << " ";
    while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < a[tmp].size(); i++)
		{
			if (!unused[a[tmp][i]])
			{
                cout << a[tmp][i] + 1 << " ";
                q.push(a[tmp][i]);
				unused[a[tmp][i]] = true;
			}
		}
	}
    cout << endl;
}

void init()
{
    int vertex, edge, u;
    cin >> vertex >> edge >> u;
	vector<vector<int>> a(vertex, vector<int>());
	for (int i = 0; i < edge; i++)
	{
		int first, last;
		cin >> first >> last;
		a[first - 1].push_back(last - 1);
		a[last - 1].push_back(first - 1);
	}
	vector<bool> unused(vertex, false);
	BFS(a, unused, u - 1);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		init();
	}
	return 0;
}