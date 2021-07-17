#include <iostream>
#include <queue>
using namespace std;

void drive() {
    int n;
    cin >> n;
    queue<long long> q;
    q.push(9);
    while (q.front() % n != 0) {
        q.push(q.front() * 10);
        q.push(q.front() * 10 + 9);
        q.pop();
    }
    cout << q.front() << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        drive();
    }
    return 0;
}
