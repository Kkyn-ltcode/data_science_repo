#include <iostream>
#include <queue>
using namespace std;

bool check(string s, int n) {
    int t = 0;
    for (int i = 0; i < s.size(); i++)
        t = t * 10 + s[i] - '0';
    return t % n == 0;
}

string res(int n) {
    string s = "9";
    queue<string> q;
    q.push(s);
    while (!check(q.front(), n)) {
        s = q.front();
        q.pop();
        string s1 = s + '0';
        string s2 = s + '9';
        q.push(s1);
        q.push(s2);
    }
    return q.front();
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n;
        cin >> n;
        cout << res(n) << endl;
        ;
    }
    return 0;
}