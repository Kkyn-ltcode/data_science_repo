#include <iostream>
#include <vector>
using namespace std;

class graph {
   public:
    int vertices, edges, vertex;
    vector<vector<int>> list;
    vector<bool> unused;
    void function();
    void input();
    void DFS(int);
};

void graph::DFS(int v) {
    unused[v - 1] = true;
    cout << v << " ";
    for (int i = 0; i < list[v - 1].size(); i++) {
        if (!unused[list[v - 1][i]])
            DFS(list[v - 1][i] + 1);
    }
}

void graph::input() {
    cin >> vertices >> edges >> vertex;
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
    DFS(vertex);
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