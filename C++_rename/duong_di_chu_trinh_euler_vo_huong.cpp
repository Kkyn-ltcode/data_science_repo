#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int find_odd_lever_vertex(vector<vector<int>> a)
{
	int total_odd_lever_vertex = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i].size() % 2 != 0)
			total_odd_lever_vertex++;
	return total_odd_lever_vertex;
}

void DFS(vector<vector<int>> a, vector<bool> &unused, int u)
{
	stack<int> s;
	s.push(u);
	unused[u] = true;
	while (!s.empty())
	{
		int tmp = s.top();
		s.pop();
		for (int i = 0; i < a[tmp].size(); i++)
		{
			if (!unused[a[tmp][i]])
			{
				s.push(tmp);
				s.push(a[tmp][i]);
				unused[a[tmp][i]] = true;
				break;
			}
		}
	}
}

bool is_all_vertex_has_used(vector<bool> unused, int vertex)
{
	for (int i = 0; i < vertex; i++)
		if (!unused[i])
			return false;
	return true;
}

bool is_connected_graph(vector<vector<int>> a, int vertex)
{
	vector<bool> unused(vertex, false);
	DFS(a, unused, 0);
	if (is_all_vertex_has_used(unused, vertex))
		return true;
	return false;
}

void graph(vector<vector<int>> a, int vertex)
{
	if (is_connected_graph(a, vertex))
	{
		int result = find_odd_lever_vertex(a);
		if (result == 2)
			cout << 1 << endl;
		else if (result == 0)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}
	else
		cout << 0 << endl;
}

void init()
{
	int vertex, edge;
	cin >> vertex >> edge;
	vector<vector<int>> a(vertex, vector<int>());
	for (int i = 0; i < edge; i++)
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
	}
	return 0;
}