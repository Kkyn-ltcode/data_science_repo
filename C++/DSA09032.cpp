#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class graph {
   public:
    int vertices, edges;
    vector<vector<int>> list;
    void function();
    void input();
    void num_of_connecting();
    int BFS(int, vector<bool> &);
};

int graph::BFS(int v, vector<bool> &visited) {
    visited[v] = true;
    queue<int> q;
    q.push(v);
    int num = 1;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < list[tmp].size(); i++) {
            if (!visited[list[tmp][i]]) {
                visited[list[tmp][i]] = true;
                num++;
                q.push(list[tmp][i]);
            }
        }
    }
    return num;
}

void graph::num_of_connecting() {
    vector<bool> visited(vertices, false);
    int ans = 0;
    for (int i = 0; i < vertices; i++)
        if (!visited[i])
            ans = max(ans, BFS(i, visited));
    cout << ans << endl;
}

void graph::input() {
    cin >> vertices >> edges;
    list.resize(vertices);
    for (int i = 0; i < edges; i++) {
        int source, destination;
        cin >> source >> destination;
        list[source - 1].push_back(destination - 1);
        list[destination - 1].push_back(source - 1);
    }
}

void graph::function() {
    input();
    num_of_connecting();
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