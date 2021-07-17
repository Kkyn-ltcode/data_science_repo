#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class graph {
   public:
    int vertices, edges;
    vector<vector<int>> list;
    vector<bool> unused;
    void function();
    void input();
    void BFS(int);
    bool is_connected();
};

bool graph::is_connected() {
    for (int i = 0; i < vertices; i++)
        if (!unused[i])
            return false;
    return true;
}

void graph::BFS(int v) {
    queue<int> q;
    q.push(v - 1);
    unused[v - 1] = true;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < list[tmp].size(); i++) {
            if (!unused[list[tmp][i]]) {
                q.push(list[tmp][i]);
                unused[list[tmp][i]] = true;
            }
        }
    }
}

void graph::input() {
    cin >> vertices >> edges;
    list.resize(vertices);
    unused.resize(vertices, false);
    for (int i = 0; i < edges; i++) {
        int source, destination;
        cin >> source >> destination;
        list[source - 1].push_back(destination - 1);
    }
}

void graph::function() {
    input();
    BFS(1);
    if (is_connected())
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        graph g;
        g.function();
    }
    return 0;
}