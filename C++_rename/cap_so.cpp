#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dp(vector<pair<int, int>> p, int n) {
    vector<vector<pair<int, int>>> x(n);
    // x stores maximum length of chain of
    // p[0..i] that ends with p[i]
    x[0].push_back(p[0]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (p[j].second < p[i].first &&
                x[j].size() > x[i].size())
                x[i] = x[j];
        }
        x[i].push_back(p[i]);
    }
    vector<pair<int, int>> max_chain;
    for (int i = 0; i < n; i++)
        if (x[i].size() > max_chain.size())
            max_chain = x[i];
    return max_chain.size();
}

int driver() {
    int n;
    cin >> n;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int f, s;
        cin >> f >> s;
        p.push_back(make_pair(f, s));
    }
    sort(p.begin(), p.end());
    return dp(p, n);
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        cout << driver() << endl;
    }
    return 0;
}
