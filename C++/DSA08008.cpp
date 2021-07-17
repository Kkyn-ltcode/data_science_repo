#include <iostream>
#include <queue>
using namespace std;

void res(long long n) {
    long long c = 0;
    queue<long long> q;
    q.push(1);
    while (!q.empty()) {
        long long s = q.front();
        q.pop();
        if (s % n == 0) {
            cout << s << endl;
            break;
        }
        q.push(s * 10);
        q.push(s * 10 + 1);
    }
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long n;
        cin >> n;
        res(n);
    }
    return 0;
}