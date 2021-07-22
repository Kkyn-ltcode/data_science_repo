#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define r 1000000007

long long wiring(long long a[], long long n) {
    priority_queue<long long, vector<long long>,
                   greater<long long>>
        rq(a, a + n);
    long long sum = 0;
    while (rq.size() > 1) {
        long long first = rq.top();
        rq.pop();
        long long second = rq.top();
        rq.pop();
        sum %= r;
        sum += (first % r + second % r) % r;
        sum %= r;
        rq.push((first % r + second % r) % r);
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << wiring(a, n) << endl;
    }
    return 0;
}