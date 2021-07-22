#include <iostream>
#include <queue>
using namespace std;

void res(queue<int>& q, int key) {
    switch (key) {
        case 1: {
            cout << q.size() << endl;
            break;
        }
        case 2: {
            if (q.empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            break;
        }
        case 3: {
            int value;
            cin >> value;
            q.push(value);
            break;
        }
        case 4: {
            if (!q.empty())
                q.pop();
            break;
        }
        case 5: {
            if (!q.empty())
                cout << q.front() << endl;
            else
                cout << "-1" << endl;
            break;
        }
        case 6: {
            if (!q.empty())
                cout << q.back() << endl;
            else
                cout << "-1" << endl;
            break;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n;
        cin >> n;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            int key;
            cin >> key;
            res(q, key);
        }
    }
    return 0;
}