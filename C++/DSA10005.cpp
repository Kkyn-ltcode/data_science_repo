#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int has_euler_cycle() {
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<int>> a(vertex, vector<int>());
    unordered_map<int, int> um;
    for (int i = 0; i < edge; i++) {
        int first, last;
        cin >> first >> last;
        a[first - 1].push_back(last - 1);
        um[last - 1]++;
    }
    for (int i = 0; i < vertex; i++)
        if (a[i].size() != um[i])
            return 0;
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << has_euler_cycle() << endl;
    }
    return 0;
}