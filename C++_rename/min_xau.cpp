#include <iostream>
#include <map>
#include <queue>
using namespace std;

void greedy() {
    int k;
    string s;
    cin >> k >> s;
    map<char, int> m;
    for (int i = 0; i < s.size(); i++)
        m[s[i]]++;
    map<char, int>::iterator it = m.begin();
    priority_queue<int> pq;
    for (it; it != m.end(); it++)
        pq.push(it->second);
    while (k--) {
        int q = pq.top();
        pq.pop();
        q--;
        pq.push(q);
    }
    int sum = 0;
    while (!pq.empty()) {
        int q = pq.top();
        pq.pop();
        sum += q * q;
    }
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        greedy();
    }
    return 0;
}