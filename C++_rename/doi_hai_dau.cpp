#include <deque>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    deque<int> dq;
    for (int x = 0; x < t; x++) {
        string s;
        cin >> s;
        if (s == "PUSHFRONT") {
            int n;
            cin >> n;
            dq.push_front(n);
        } else if (s == "PRINTFRONT") {
            if (!dq.empty())
                cout << dq.front() << endl;
            else
                cout << "NONE" << endl;
        } else if (s == "POPFRONT") {
            if (!dq.empty())
                dq.pop_front();
        } else if (s == "PUSHBACK") {
            int n;
            cin >> n;
            dq.push_back(n);
        } else if (s == "PRINTBACK") {
            if (!dq.empty())
                cout << dq.back() << endl;
            else
                cout << "NONE" << endl;
        } else if (s == "POPBACK") {
            if (!dq.empty())
                dq.pop_back();
        }
    }
    return 0;
}