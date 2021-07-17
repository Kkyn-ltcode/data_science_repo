#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& a) {
    cout << "[";
    for (int i = 0; i < a.size() - 1; i++) {
        a[i] = a[i] + a[i + 1];
        cout << a[i];
        if (i < a.size() - 2)
            cout << " ";
    }
    a.pop_back();
    cout << "]" << endl;
}

int main() {
    int t;
    cin >> t;
    for (int m = 0; m < t; m++) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            a.push_back(v);
        }
        cout << "[";
        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i < n - 1)
                cout << " ";
        }
        cout << "]" << endl;
        for (int i = 1; i < n; i++)
            print(a);
    }
    return 0;
}