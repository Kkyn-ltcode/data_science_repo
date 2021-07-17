#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> a, vector<bool> &unused,
		 int u, int vertex, int start, int end)
{
	queue<int> q;
	q.push(u);
	unused[u] = true;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < a[tmp].size(); i++)
		{
			if ((tmp == start && a[tmp][i] == end) ||
				(tmp == end && a[tmp][i] == start))
				continue;
			if (!unused[a[tmp][i]])
			{
				unused[a[tmp][i]] = true;
				q.push(a[tmp][i]);
			}
		}
	}
}

bool test(vector<bool> unused, int vertex)
{
	for (int i = 0; i < vertex; i++)
		if (unused[i] == false)
			return true;
	return false;
}

void graph(vector<vector<int>> a, int vertex)
{
	for (int i = 0; i < vertex; i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			if (i < a[i][j])
			{
				vector<bool> unused(vertex, false);
				BFS(a, unused, 0, vertex, i, a[i][j]);
				if (test(unused, vertex))
					cout << i + 1 << " " << a[i][j] + 1 << " ";
			}
		}
	}
}

void init()
{
	int vertex, edge;
	cin >> vertex >> edge;
	vector<vector<int>> a(vertex, vector<int>());
	for (int i = 1; i <= edge; i++)
	{
		int first, last;
		cin >> first >> last;
		a[first - 1].push_back(last - 1);
		a[last - 1].push_back(first - 1);
	}
	graph(a, vertex);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		init();
		cout << endl;
	}
	return 0;
}