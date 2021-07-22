#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n, c = 1;
        cin >> n;
        vector<int> a(n, 0), b(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++)
            p.push_back(make_pair(b[i], a[i]));
        sort(p.begin(), p.end());
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (p[j].second >= p[i].first) {
                i = j;
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}