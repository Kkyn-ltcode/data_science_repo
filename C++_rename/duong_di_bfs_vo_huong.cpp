#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> a, vector<bool> unused,
         vector<int>& front, int u)
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
			if (!unused[a[tmp][i]])
			{
                front[a[tmp][i]] = tmp;
				q.push(a[tmp][i]);
				unused[a[tmp][i]] = true;
			}
		}
	}
}

void print_path(vector<int> front, int start, int end)
{
    vector<int> path;
    path.push_back(end + 1);
    while (front[end] != start)
    {
        path.push_back(front[end] + 1);
        end = front[end];
    }
    path.push_back(start + 1);
    for (int i = path.size() - 1; i >= 0;i--)
        cout << path[i] << " ";
    cout << endl;
}

void init()
{
    int vertex, edge, start, end;
    cin >> vertex >> edge >> start >> end;
    vector<vector<int>> a(vertex, vector<int>());
    for (int i = 0; i < edge; i++)
    {
        int first, last;
        cin >> first >> last;
        a[first - 1].push_back(last - 1);
        a[last - 1].push_back(first - 1);
    }
    vector<bool> unused(vertex, false);
    vector<int> front(vertex, -1);
    BFS(a, unused, front, start - 1);
    print_path(front, start - 1, end - 1);
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