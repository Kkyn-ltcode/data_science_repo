#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

long long remove_k_characters(string s, long long k) {
    long long n = s.size();
    if (k >= n)
        return 0;
    unordered_map<long long, long long> um;
    for (long long i = 0; i < n; i++)
        um[s[i] - 'A']++;
    priority_queue<long long> pq;
    for (long long i = 0; i < 26; i++)
        if (um[i] != 0)
            pq.push(um[i]);
    while (k--) {
        long long tmp = pq.top();
        pq.pop();
        tmp--;
        pq.push(tmp);
    }
    long long result = 0;
    while (!pq.empty()) {
        long long tmp = pq.top();
        pq.pop();
        result += tmp * tmp;
    }
    return result;
}

long long init() {
    long long k;
    string s;
    cin >> k;
    cin >> s;
    return remove_k_characters(s, k);
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        cout << init() << endl;
    }
    return 0;
}