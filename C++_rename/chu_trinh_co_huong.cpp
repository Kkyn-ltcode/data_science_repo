#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool BFS(vector<vector<int>> a, vector<bool> unused, int u, int vertex) {
    vector<int> front(vertex, -1);
    queue<int> q;
    q.push(u);
    unused[u] = true;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < a[tmp].size(); i++) {
            if (!unused[a[tmp][i]]) {
                front[a[tmp][i]] = tmp;
                q.push(a[tmp][i]);
                unused[a[tmp][i]] = true;
            } else if (front[tmp] != a[tmp][i])
                return true;
        }
    }
    return false;
}

string graph(vector<vector<int>> a, int vertex) {
    vector<bool> unused(vertex, false);
    for (int i = 0; i < vertex; i++)
        if (!unused[i] && BFS(a, unused, i, vertex))
            return "YES";
    return "NO";
}

void init() {
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<int>> a(vertex, vector<int>());
    for (int i = 0; i < edge; i++) {
        int first, last;
        cin >> first >> last;
        a[first - 1].push_back(last - 1);
    }
    cout << graph(a, vertex) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
    }
    return 0;
}