#include <iostream>
#include <vector>
using namespace std;

class binary_tree {
   public:
    void function();
    bool is_BST(vector<int>, int);
};

bool binary_tree::is_BST(vector<int> a, int n) {
    if (n == 0 || n == 1)
        return true;
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

void binary_tree::function() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (is_BST(a, n))
        cout << 1;
    else
        cout << 0;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        binary_tree b;
        b.function();
    }
    return 0;
}