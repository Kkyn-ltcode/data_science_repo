#include <iostream>
#include <vector>
using namespace std;

class graph {
   public:
    int vertices;
    vector<vector<int>> list;
    void function();
    void input();
    bool has_cycle(int, vector<bool> &, int);
    bool is_tree();
};

bool graph::is_tree() {
    vector<bool> visited(vertices, false);
    if (has_cycle(0, visited, -1))
        return false;
    for (int i = 0; i < vertices; i++)
        if (!visited[i])
            return false;
    return true;
}

bool graph::has_cycle(int v, vector<bool> &visited, int parent) {
    visited[v] = true;
    for (int i = 0; i < list[v].size(); i++) {
        if (!visited[list[v][i]]) {
            if (has_cycle(list[v][i], visited, v))
                return true;
        } else if (list[v][i] != parent)
            return true;
    }
    return false;
}

void graph::input() {
    cin >> vertices;
    list.resize(vertices);
    int edges = vertices - 1;
    for (int i = 0; i < edges; i++) {
        int source, destination;
        cin >> source >> destination;
        list[source - 1].push_back(destination - 1);
        list[destination - 1].push_back(source - 1);
    }
}

void graph::function() {
    input();
    if (is_tree())
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