#include <iostream>
#include <queue>
#include <set>
using namespace std;

int s_t_transform(int s, int t) {
    int count = 0;
    while (t != s) {
        if (t < s) {
            t += 1;
            count++;
        } else {
            if (t % 2 != 0) {
                t += 1;
                t /= 2;
                count += 2;
            } else {
                t /= 2;
                count++;
            }
        }
    }
    return count;
}

// struct node {
//     int value;
//     int level;
// };

// int s_t_transform(int s, int t) {
//     set<int> used;
//     node n = {s, 0};
//     queue<node> q;
//     q.push(n);
//     while (!q.empty()) {
//         node tmp = q.front();
//         q.pop();
//         if (tmp.value == t)
//             return tmp.level;
//         used.insert(tmp.value);
//         if (tmp.value * 2 == t || tmp.value - 1 == t)
//             return tmp.level + 1;
//         if (used.find(tmp.value * 2) == used.end()) {
//             n.value = tmp.value * 2;
//             n.level = tmp.level + 1;
//             q.push(n);
//         }
//         if (tmp.value - 1 >= 0 && used.find(tmp.value - 1) == used.end()) {
//             n.value = tmp.value - 1;
//             n.level = tmp.level + 1;
//             q.push(n);
//         }
//     }
// }

int init() {
    int s, t;
    cin >> s >> t;
    return s_t_transform(s, t);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << init() << endl;
    }
    return 0;
}