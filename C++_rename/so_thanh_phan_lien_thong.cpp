#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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

void graph(vector<vector<int>> a, vector<bool> unused, int vertex)
{
    int num_of_connected = 0;
    for (int i = 0; i < vertex; i++)
    {
        if (!unused[i])
        {
            num_of_connected++;
            DFS(a, unused, i);
        }
    }
    cout << num_of_connected << endl;
}

void init()
{
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<int>> a(1005, vector<int>());
    for (int i = 0; i < edge; i++)
    {
        int first, last;
        cin >> first >> last;
        a[first - 1].push_back(last - 1);
        a[last - 1].push_back(first - 1);
    }
    vector<bool> unused(vertex, false);
    graph(a, unused, vertex);
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