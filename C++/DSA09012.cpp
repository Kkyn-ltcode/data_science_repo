#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<vector<int>> a, vector<bool> &unused, int u) {
    queue<int> q;
    q.push(u);
    unused[u] = true;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < a[tmp].size(); i++) {
            if (!unused[a[tmp][i]]) {
                q.push(a[tmp][i]);
                unused[a[tmp][i]] = true;
            }
        }
    }
}

bool is_connected(vector<bool> unused, int vertex) {
    for (int i = 0; i < vertex; i++)
        if (!unused[i])
            return false;
    return true;
}

void graph(vector<vector<int>> a, int vertex) {
    for (int i = 0; i < vertex; i++) {
        vector<bool> unused(vertex, false);
        unused[i] = true;
        if (i == 0)
            BFS(a, unused, 1);
        else
            BFS(a, unused, 0);
        if (!is_connected(unused, vertex))
            cout << i + 1 << " ";
    }
}

void init() {
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<int>> a(vertex, vector<int>());
    for (int i = 0; i < edge; i++) {
        int first, last;
        cin >> first >> last;
        a[first - 1].push_back(last - 1);
        a[last - 1].push_back(first - 1);
    }
    graph(a, vertex);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        cout << endl;
    }
    return 0;
}