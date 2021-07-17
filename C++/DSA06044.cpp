#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class sorting {
   public:
    int n;
    vector<int> a;
    void input();
    void solve();
};

bool compare(int x, int y) {
    return x > y;
}

void sorting::solve() {
    vector<int> tmp1, tmp2;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            tmp1.push_back(a[i]);
        else
            tmp2.push_back(a[i]);
    }
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end(), compare);
    int index1 = 0, index2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << tmp1[index1] << " ";
            index1++;
        } else {
            cout << tmp2[index2] << " ";
            index2++;
        }
    }
    cout << endl;
}

void sorting::input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main() {
    sorting s;
    s.input();
    s.solve();
    return 0;
}