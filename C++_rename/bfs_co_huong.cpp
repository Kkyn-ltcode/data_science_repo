#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class graph {
   public:
    int vertices, edges, vertex;
    vector<vector<int>> list;
    vector<bool> unused;
    void function();
    void input();
    void BFS(int);
};

void graph::BFS(int v) {
    queue<int> q;
    q.push(v);
    unused[v - 1] = true;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        cout << tmp << " ";
        for (int i = 0; i < list[tmp - 1].size(); i++) {
            if (!unused[list[tmp - 1][i]]) {
                q.push(list[tmp - 1][i] + 1);
                unused[list[tmp - 1][i]] = true;
            }
        }
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
    BFS(vertex);
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