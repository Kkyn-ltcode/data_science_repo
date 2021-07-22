#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void gray_code() {
    int n;
    cin >> n;
    vector<string> s;
    s.push_back("0");
    s.push_back("1");
    int i = 1;
    while (i < n) {
        vector<string> tmp = s;
        for (int j = 0; j < s.size(); j++)
            s[j] = "0" + s[j];
        reverse(tmp.begin(), tmp.end());
        for (int j = 0; j < tmp.size(); j++)
            s.push_back("1" + tmp[j]);
        i++;
    }
    for (int j = 0; j < s.size(); j++)
        cout << s[j] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        gray_code();
    }
    return 0;
}