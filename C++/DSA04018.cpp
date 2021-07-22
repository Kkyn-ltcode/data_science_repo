#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int m = 0; m < t; m++) {
        unordered_map<int, int> u;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            u[v]++;
        }
        cout << u[0] << endl;
    }
    return 0;
}