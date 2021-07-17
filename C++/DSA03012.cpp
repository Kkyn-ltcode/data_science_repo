#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool check(string s) {
    unordered_map<char, int> m;
    int max = 0;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]]++;
        if (m[s[i]] > max)
            max = m[s[i]];
    }
    if (max <= s.size() - max + 1)
        return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int m = 0; m < t; m++) {
        string s;
        cin >> s;
        if (check(s))
            cout << "1" << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}