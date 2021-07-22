#include <iostream>
#include <string>
#include <vector>
using namespace std;

void to_graph(string s, vector<int>& graph) {
    for (int i = 0; i < s.size(); i++) {
        int d = 0;
        while (isdigit(s[i])) {
            d = d * 10 + s[i] - '0';
            i += 1;
        }
        graph.push_back(d);
    }
}

void convert(vector<vector<int>> graph) {
    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph[i].size(); j++)
            if (graph[i][j] > i)
                cout << i + 1 << " " << graph[i][j] << endl;
}

int main() {
    int vertex;
    cin >> vertex;
    cin.ignore();
    vector<vector<int>> graph(vertex, vector<int>());
    for (int i = 0; i < vertex; i++) {
        string s = "";
        while (s == "")
            getline(cin, s);
        to_graph(s, graph[i]);
    }
    convert(graph);
    return 0;
}