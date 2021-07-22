#include <iostream>
#include <vector>
using namespace std;

class graph {
   public:
    int vertices, edges;
    vector<vector<int>> list;
    void function();
    void input();
    bool DFS(int, vector<bool> &, vector<bool> &, vector<bool> &);
    bool has_cycle();
};

bool graph::has_cycle() {
    vector<bool> unvisited(vertices, true);
    vector<bool> visiting(vertices, false);
    vector<bool> visited(vertices, false);
    for (int i = 0; i < vertices; i++) {
        if (unvisited[i]) {
            if (DFS(i, unvisited, visiting, visited))
                return true;
        }
    }
    return false;
}

bool graph::DFS(int v, vector<bool> &unvisited,
                vector<bool> &visiting, vector<bool> &visited) {
    unvisited[v] = false;
    visiting[v] = true;
    for (int i = 0; i < list[v].size(); i++) {
        if (visited[list[v][i]])
            continue;
        if (visiting[list[v][i]])
            return true;
        if (DFS(list[v][i], unvisited, visiting, visited))
            return true;
    }
    visiting[v] = false;
    visited[v] = true;
    return false;
}

void graph::input() {
    cin >> vertices >> edges;
    list.resize(vertices);
    for (int i = 0; i < edges; i++) {
        int source, destination;
        cin >> source >> destination;
        list[source - 1].push_back(destination - 1);
    }
}

void graph::function() {
    input();
    if (has_cycle())
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