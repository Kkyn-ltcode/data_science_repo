#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class graph {
   public:
    int vertices, edges, start, end, quest;
    vector<vector<int>> list;
    void function();
    void input();
    bool BFS(int);
};

bool graph::BFS(int v) {
    vector<bool> unused(vertices, false);
    queue<int> q;
    q.push(v - 1);
    unused[v - 1] = true;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        if (tmp + 1 == end)
            return true;
        for (int i = 0; i < list[tmp].size(); i++) {
            if (!unused[list[tmp][i]]) {
                if (list[tmp][i] + 1 == end)
                    return true;
                q.push(list[tmp][i]);
                unused[list[tmp][i]] = true;
            }
        }
    }
    return false;
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
    cin >> quest;
    vector<string> ans;
    while (quest--) {
        cin >> start >> end;
        if (BFS(start))
            ans.push_back("YES");
        else
            ans.push_back("NO");
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
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