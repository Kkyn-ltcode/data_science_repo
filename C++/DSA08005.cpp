#include <iostream>
#include <queue>
using namespace std;

void res(int n) {
    string s = "1";
    queue<string> q;
    q.push(s);
    while (n--) {
        s = q.front();
        q.pop();
        cout << s << " ";
        string s1 = s + '0';
        string s2 = s + '1';
        q.push(s1);
        q.push(s2);
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        int n;
        cin >> n;
        res(n);
    }
    return 0;
}