#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int x = 0; x < t; x++)
	{
		int vertex, edge;
		cin >> vertex >> edge;
		int begin, end;
		vector<vector<int>>graph(vertex, vector<int>());
		for (int i = 0; i < edge; i++)
		{
			cin >> begin >> end;
			graph[begin - 1].push_back(end);
		}
		for (int i = 0; i < vertex; i++)
		{
			cout << i + 1 << ": ";
			for (int j = 0; j < graph[i].size(); j++)
				cout << graph[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}