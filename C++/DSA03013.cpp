#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool check(string s, int d) {
    unordered_map<char, int> m;
    int max = 0;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]]++;
        if (m[s[i]] > max)
            max = m[s[i]];
    }
    int res = s.size() / (d - 1);
    if (max < res)
        return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int m = 0; m < t; m++) {
        int d;
        cin >> d;
        string s;
        cin >> s;
        if (check(s, d))
            cout << "1" << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}