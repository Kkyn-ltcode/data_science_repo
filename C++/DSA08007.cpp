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
        if (s <= n) {
            c++;
            q.push(s * 10);
            q.push(s * 10 + 1);
        }
    }
    cout << c << endl;
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